# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(minimal)

# set(rp2_common_dir ${ZEPHYR_HAL_RPI_PICO_MODULE_DIR}/src/rp2_common)

# set(PICO_CYW43_SUPPORTED 1)

# zephyr_include_directories(
#     ${rp2_common_dir}/pico_cyw43_arch/include
#     ${rp2_common_dir}/pico_cyw43_driver/include
#     ${ZEPHYR_HAL_RPI_PICO_MODULE_DIR}/lib/cyw43-driver/src
#   )


target_sources(app PRIVATE src/main.c)
