/*
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_WIFI_INFINEON_AIROC_H_
#define ZEPHYR_INCLUDE_DRIVERS_WIFI_INFINEON_AIROC_H_

#include <whd_buffer_api.h>

/**
 * \brief This function returns pointer type to handle instance
 *        of whd interface (whd_interface_t) which allocated in
 *        Zephyr AIROC driver (drivers/wifi/infineon/airoc_wifi.c)
 */

whd_interface_t airoc_wifi_get_whd_interface(void);

#endif  /* ZEPHYR_INCLUDE_DRIVERS_WIFI_INFINEON_AIROC_H_ */