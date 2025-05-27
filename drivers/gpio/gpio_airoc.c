/*

 */

#define DT_DRV_COMPAT infineon_airoc_gpio

#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/gpio/gpio_utils.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/wifi/infineon/airoc_wifi_if.h>

#include <whd_cdc_bdc.h>

LOG_MODULE_REGISTER(infineon_airoc_gpio, CONFIG_GPIO_LOG_LEVEL);

static bool led_set = true;

struct vnd_gpio_config {
	/* gpio_driver_config needs to be first */
	struct gpio_driver_config common;
};

struct vnd_gpio_data {
	/* gpio_driver_data needs to be first */
	struct gpio_driver_data common;
};

static int vnd_gpio_pin_configure(const struct device *port,
				  gpio_pin_t pin,
				  gpio_flags_t flags)
{
	LOG_ERR("Configuring Infineon GPIO pin");
    printk("Configuring gpio driver\n");

	return 0;
}

static int vnd_gpio_port_get_raw(const struct device *port,
				 gpio_port_value_t *value)
{
	return -ENOTSUP;
}

static int vnd_gpio_port_set_masked_raw(const struct device *port,
					gpio_port_pins_t mask,
					gpio_port_value_t value)
{
	return -ENOTSUP;
}

static int vnd_gpio_port_set_bits_raw(const struct device *port,
				      gpio_port_pins_t pins)
{
	return -ENOTSUP;
}

static int vnd_gpio_port_clear_bits_raw(const struct device *port,
					gpio_port_pins_t pins)
{
	return -ENOTSUP;
}

static int vnd_gpio_port_toggle_bits(const struct device *port,
				     gpio_port_pins_t pins)
{
	printk("Toggling GPIO driver\n");

	whd_interface_t whd_interface = airoc_wifi_get_whd_interface();
	whd_buffer_t buffer;

	uint8_t * gpio_on_data = (uint8_t *)whd_cdc_get_iovar_buffer(whd_interface->whd_driver, &buffer, 8, "gpioout");
	
	gpio_on_data[0] = 1;

	if (led_set)
	{
		LOG_ERR("LED Off");
		gpio_on_data[4] = 0;
	} else {
		LOG_ERR("LED On");
		gpio_on_data[4] = 1;
	}

	whd_cdc_send_iovar(whd_interface, CDC_SET, (whd_buffer_t *)buffer, NULL);

	led_set = !(led_set);

	return 0;
}

static DEVICE_API(gpio, infineon_airoc_gpio_api) = {
	.pin_configure = vnd_gpio_pin_configure,
	.port_get_raw = vnd_gpio_port_get_raw,
	.port_set_masked_raw = vnd_gpio_port_set_masked_raw,
	.port_set_bits_raw = vnd_gpio_port_set_bits_raw,
	.port_clear_bits_raw = vnd_gpio_port_clear_bits_raw,
	.port_toggle_bits = vnd_gpio_port_toggle_bits,
};

#define VND_GPIO_INIT(n)						\
	static const struct vnd_gpio_config vnd_gpio_config_##n = {	\
		.common = {						\
			.port_pin_mask = GPIO_PORT_PIN_MASK_FROM_DT_INST(n), \
		},							\
	};								\
									\
	static struct vnd_gpio_data vnd_gpio_data_##n;			\
									\
	DEVICE_DT_INST_DEFINE(n, NULL, NULL, &vnd_gpio_data_##n,	\
			      &vnd_gpio_config_##n, POST_KERNEL,	\
			      CONFIG_GPIO_INIT_PRIORITY,		\
			      &infineon_airoc_gpio_api);

DT_INST_FOREACH_STATUS_OKAY(VND_GPIO_INIT)