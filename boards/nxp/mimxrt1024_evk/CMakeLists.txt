#
# Copyright 2022 NXP
#
# SPDX-License-Identifier: Apache-2.0
#


if(CONFIG_NXP_IMXRT_BOOT_HEADER)
  zephyr_library()
  if(NOT DEFINED CONFIG_BOARD_MIMXRT1024_EVK)
    message(WARNING "It appears you are using the board definition for "
     "the MIMXRT1024-EVK, but targeting a custom board. You may need to "
     "update your flash configuration or device configuration data blocks")
  endif()
  set(RT1024_BOARD_DIR
    "${ZEPHYR_HAL_NXP_MODULE_DIR}/mcux/mcux-sdk-ng/boards/evkmimxrt1024")
  if(CONFIG_BOOT_FLEXSPI_NOR)
    # Include flash configuration block for RT1024 EVK from NXP's HAL.
    # This configuration block may need modification if another flash chip is
    # used on your custom board. See NXP AN12238 for more information.
    zephyr_compile_definitions(XIP_BOOT_HEADER_ENABLE=1)
    zephyr_compile_definitions(BOARD_FLASH_SIZE=CONFIG_FLASH_SIZE*1024)
    zephyr_library_sources(${RT1024_BOARD_DIR}/xip/evkmimxrt1024_flexspi_nor_config.c)
    zephyr_library_include_directories(${RT1024_BOARD_DIR}/xip)
  endif()
  if(CONFIG_DEVICE_CONFIGURATION_DATA)
    # Include device configuration data block for RT1024 EVK from NXP's HAL.
    # This configuration block may need modification if another SDRAM chip
    # is used on your custom board.
    zephyr_compile_definitions(XIP_BOOT_HEADER_DCD_ENABLE=1)
    zephyr_library_sources(${RT1024_BOARD_DIR}/dcd.c)
  else()
    if(CONFIG_SRAM_BASE_ADDRESS EQUAL 0x80000000)
      message(WARNING "You are using SDRAM as RAM but no device "
        "configuration data (DCD) is included. This configuration may not boot")
    endif()
  endif()
endif()

if(CONFIG_MCUX_GPT_TIMER)
  message(WARNING "You appear to be using the GPT hardware timer. "
    "This timer will enable lower power modes, but at the cost of reduced "
    "hardware timer resolution")
endif()
