# Comet46 Keyboard Firmware
Firmware for Nordic MCUs used in the Comet46 Keyboard, contains precompiled .hex files, as well as sources buildable with the Nordic SDK

The firmware was originally developed by [reversebias](https://github.com/reversebias) for the [Mitosis keyboard](https://github.com/reversebias/mitosis) and has been modified to work with Comet46.

The firmware has been updated based on [repne's fork of mitosis](https://github.com/repne/mitosis).
This update "should" extend the battery life from 1-2 months to 6 months. (Actual battery life is currently being tested.)

## Install dependencies

Tested on Ubuntu 16.04.2, but should be able to find alternatives on all distros. 

```
sudo apt install openocd gcc-arm-none-eabi
```

## Download Nordic SDK

Nordic does not allow redistribution of their SDK or components, so download and extract from their site:

https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v11.x.x/

Firmware written and tested with version 11

```
unzip nRF5_SDK_11.0.0_89a8197.zip  -d nRF5_SDK_11
cd nRF5_SDK_11
```

## Toolchain set-up

A cofiguration file that came with the SDK needs to be changed. Assuming you installed gcc-arm with apt, the compiler root path needs to be changed in /components/toolchain/gcc/Makefile.posix, the line:
```
GNU_INSTALL_ROOT := /usr/local/gcc-arm-none-eabi-4_9-2015q1
```
Replaced with:
```
GNU_INSTALL_ROOT := /usr/
```

## Clone repository
Inside nRF5_SDK_11/
```
git clone https://github.com/satt99/comet46-firmware
```

## Install udev rules
```
sudo cp comet46-firmware/49-stlinkv2.rules /etc/udev/rules.d/
```
Plug in, or replug in the programmer after this.

## OpenOCD server
The programming header on the keyboard, from right to left:  
(Check the silk screen on PCBs for orders.)
```
SWDIO
SWCLK
GND
3.3V
```

It's best to remove the battery during long sessions of debugging, as charging non-rechargeable lithium batteries isn't recommended.

Launch a debugging session with:
```
sudo openocd -f comet46-firmware/nrf-stlink.cfg
```
Should give you an output ending in:
```
Info : nrf51.cpu: hardware has 4 breakpoints, 2 watchpoints
```
Otherwise you likely have a loose or wrong wire.


## Manual programming
From the factory, these chips need to be erased:
```
echo reset halt | telnet localhost 4444
echo nrf51 mass_erase | telnet localhost 4444
```
From there, the precompiled binaries can be loaded:
```
echo reset halt | telnet localhost 4444
echo flash write_image `readlink -f precompiled/precompiled-basic-left.hex` | telnet localhost 4444
echo reset | telnet localhost 4444
```

## Automatic make and programming scripts
To use the automatic build scripts:
```
cd comet46-firmware/comet46-keyboard-basic
sudo ./program.sh
```
An openocd session should be running in another terminal, as this script sends commands to it.
