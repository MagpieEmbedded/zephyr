/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>

#include <zephyr/kernel.h>
// #include <zephyr/drivers/wifi/infineon/airoc_wifi.h>

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD_TARGET);

	// whd_interface_t i = airoc_wifi_get_whd_interface();

	return 0;
}
