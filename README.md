# RK ROYAL KLUDGE R75 - Custom QMK firmware (WIP)
Custom QMK Firmware for Royal Kludge R75 Wired ANSI Model.

| Firmware        | Features              | USB ID              |
|---------------|-----------------------|-----------------------|
| Original Firmware   | QMK, VIA      | VID:342d PID:e484| 
| Custom Firmware   | QMK, VIA      | | 
| VIA Plus OpenRGB Firmware   | QMK, VIA, OpenRGB     |  | 
| VIA Plus SignalRGB Firmware   | QMK, VIA, SignalRGB     |  | 
| VIA Plus OpenRGB & SignalRGB Firmware   | QMK, VIA, OpenRGB, SignalRGB     |  | 
|---------------|-----------------------|-----------------------|
| VIA Plus OpenRGB & SignalRGB Firmware-ISO   | QMK, VIA, OpenRGB, SignalRGB     | VID:342d PID:e483| 

## ⚠️ Disclaimer
> [!CAUTION]
> This is a custom firmware that could break your keyboard.
>
> 🛑 **Use at your own risk!** 🛑
>
> Both the PID works for my keyboard but there may be revisions in the future. Use at your own risk!

# 🥳Thanks!
Thanks to [@irfan](https://github.com/irfanjmdn/), [sdk66](https://github.com/sdk66/) and [@iamdanielv](https://github.com/iamdanielv) for their work on R65.

## ⌨️ New Keymap

I've updated the **default** keymap to work with the current source. It can be used as a starting point for customization.

I use `6 layers` for my changes, `keyboard.json` specifies that in the following section:

```json
"dynamic_keymap": {
    "layer_count": 6
}
```

## 🖥️ Compiling

You can now use QMK builder with the following command:

```shell
qmk compile -j 0 -kb rk/r75/custom -km custom
```

> the `-j 0` uses parallel build to speed it up a bit

qmk should generate a new bin file: `rk_r75_custom_custom.hex` in your qmk_firmware folder.

## 🌐 Using via

In order to use via, you may have to upload the [json specification](Custom%20VIA%20Layout.json), it can be found under the `extras` folder.

## 🥾 Bootloader and Clearing eeprom

To prevent accidental KB Bootloader triggers, I have it hidden under a layer.

- To reboot and `enter bootloader mode`:
  - hold `Fn`, then hold `RShift`, then triple tap the `q` key
- To `clear eeprom`:
  - hold `Fn`, then hold `RShift`, then triple tap the `z` key

## ⭐ Features

To use the features i use `Layer 1`
- hold `Fn`

While on `Layer 1`, you have the following available:

- `Right Alt` + `Q` - triple tap `Q` to `enter bootloader mode`
- `Right Alt` + `Z` - triple tap `Z` to `clear eeprom`

- `N` - Toggle NKRO
- `Right Shift` + `T` - Toggle SOCD
- `Right Shift` + `F3` - Toggle Numpad Layer
- `Right Shift` + `F1,F2,F3,F4,F5,F6,F7,F8` - Toggle Layers 0,2,3,4,5,6,7,8


## ⭐ VIA + OpenRGB
To use the features i use `Layer 1`
- hold `Fn`

While on `Layer 1`, you have the following available:

-  `Q` - tap once to switch to VIA mode or switch back to OpenRGB mode.


## ⭐ VIA + SignalRGB

-  After flashing the firmware, copy [`SignalRGB-Plugin-for-RK-R75.js`](SignalRGB%20Plugin%20for%20RK%20R75.js) to `%userprofile%/Documents/WhirlwindFX/plugins`.


## ⭐ VIA + SignalRGB + OpenRGB

To use the features i use `Layer 1`
- hold `Fn`

While on `Layer 1`, you have the following available:

- `Right Shift` + `O` - Toggle OpenRGB
- `Right Shift` + `S` - Toggle SignalRGB

- `Right Shift` + `Q` - triple tap `Q` to `enter bootloader mode`
- `Right Shift` + `Z` - triple tap `Z` to `clear eeprom`
- `Right Shift` + `<>` - triple tap `<>` to `clear eeprom` FOR ISO LAYOUT

- `Right Shift` + `N` - Toggle NKRO
- `Right Shift` + `T` - Toggle SOCD

-  After flashing the firmware, copy [`SignalRGB-Plugin-for-RK-R75.js`](SignalRGB%20Plugin%20for%20RK%20R75.js) to `%userprofile%/Documents/WhirlwindFX/plugins`.
