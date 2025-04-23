# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(hello_world)

add_compile_definitions(CONFIG_WPRINT_ENABLE_WHD_INFO=1)

target_sources(app PRIVATE src/main.c)
