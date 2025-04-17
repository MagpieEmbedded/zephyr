# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

add_compile_definitions(CONFIG_WPRINT_ENABLE_WHD_INFO=1)
add_compile_definitions(WPRINT_ENABLE_WHD_INFO=1)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(wifi)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
