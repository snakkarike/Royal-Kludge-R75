# RK ROYAL KLUDGE R75 - Custom QMK firmware (WIP)
Custom QMK Firmware for Royal Kludge R75 Wired ANSI Model.

| Branch        | Features              | HID                                             | PID                                                                                   |
|---------------|-----------------------|---------------------------------------------------------|----------------------------------------------------------------------------------------|
| 🔨 Master   | QMK, VIA      | 342D           | E484                         |

## ⚠️ Disclaimer
> [!CAUTION]
> This is a custom firmware that could break your keyboard.
>
> 🛑 **Use at your own risk!** 🛑
> 
> I have tried my best to make sure everything works, but I may miss something.
>
> It works for my keyboard, but there may be revisions in the future that are not compatible. Use at your own risk!

# 🥳Thanks!
Thanks to [@irfan](https://github.com/irfanjmdn/), [sdk66](https://github.com/sdk66/) and [@iamdanielv](https://github.com/iamdanielv) for their work on R65.

## ⌨️ New Keymap

I've updated the **default** keymap to work with the current source. It can be used as a starting point for customization.

I use `9 layers` for my changes, `keyboard.json` specifies that in the following section:

```json
"dynamic_keymap": {
    "layer_count": 9
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

In order to use via, you may have to upload the [json specification](extras/rk_r65_via.json), it can be found under the `extras` folder.

## 🥾 Bootloader and Clearing eeprom

To prevent accidental KB Bootloader triggers, I have it hidden under a layer.

- To reboot and `enter bootloader mode`:
  - hold `Fn`, then hold `RShift`, then triple tap the `q` key
- To `clear eeprom`:
  - hold `Fn`, then hold `RShift`, then triple tap the `z` key
