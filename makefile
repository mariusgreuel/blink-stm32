#
# makefile
# Copyright (C) 2018 Marius Greuel. All rights reserved.
#

ifndef MY_TOOLCHAIN_STM32
    $(error error : environment variable MY_TOOLCHAIN_STM32 is not defined. MY_TOOLCHAIN_STM32 must point to the tools-stm32 repository)
endif

BOARD ?= BluePill
SOURCES = main.cpp
SOURCES += drivers/STM32F1xx/src/system_stm32f1xx.c drivers/STM32F1xx/src/startup_stm32f103xb.s
CPPFLAGS = -Idrivers/CMSIS/include -Idrivers/STM32F1xx/include -Idrivers/STM32F1xx_HAL/include
LDFLAGS = -TSTM32F103C8Tx_FLASH.ld

include $(MY_TOOLCHAIN_STM32)/build/boards.mk
include $(MY_TOOLCHAIN_STM32)/build/stm32.mk
