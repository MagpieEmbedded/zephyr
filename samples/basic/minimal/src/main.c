/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>

#include <hardware/gpio.h>
#include <pico/cyw43_arch.h>

int main(void)
{
#ifdef CONFIG_SAMPLE_DO_OUTPUT
	printk("Hello World from minimal!\n");
#endif

	cyw43_arch_init();

	cyw43_arch_gpio_put(0, true);

	return 0;
}
