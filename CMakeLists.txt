cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include($ENV{FREERTOS_KERNEL_PATH}/portable/ThirdParty/GCC/RP2350_ARM_NTZ/FreeRTOS_Kernel_import.cmake)
set(PICO_BOARD pico2_w)
project(app C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(blink main.c)
target_include_directories(blink PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(blink
    pico_stdlib
    FreeRTOS-Kernel
    FreeRTOS-Kernel-Heap4
    pico_cyw43_arch_none
)


pico_add_extra_outputs(blink)
