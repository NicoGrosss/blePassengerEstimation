# How to build
## Initialize environment
- Clone the pico-sdk and FreeRTOS pico kernel to a directory of your choice
    - ```git clone https://github.com/RaspberryPi/pico-sdk --recurse-submodules```
    - ```git clone https://github.com/raspberrypi/FreeRTOS-Kernel```
- export PICO_SDK_PATH and FREERTOS_KERNEL_PATH as path variables

## Build (only when CMakeLists.txt or FreeRTOSConfig.h is changed)
- run buildCommand.sh

## Compiling
- run ```make``` from the build-pico2 folder

## Flashing
- press BOOTSEL on the pico while plugging the USB in
- Copy the *.uf2 file in the picos file system
- The pico will reboot and execute the code