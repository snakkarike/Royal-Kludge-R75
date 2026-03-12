# ⌨️ Royal Kludge R75 - Custom QMK Firmware

A high-performance, feature-rich custom QMK firmware for the **Royal Kludge R75 (Wired ANSI/ISO)**. This project aims to unlock the full potential of the R75, providing advanced features like SOCD cleaning, OpenRGB/SignalRGB integration, and highly customizable layers.

---

## 🚀 Key Features

- **QMK & VIA Support**: Full customization through the powerful QMK firmware and easy-to-use VIA interface.
- **⚡ SOCD Cleaner**: Simultaneous Opposing Cardinal Directions cleaning (Last Win) - essential for competitive gaming (e.g., CS2, Valorant).
- **🕹️ NKRO (N-Key Rollover)**: Never miss a keystroke with full N-key rollover support.
- **🌈 Advanced RGB Integration**:
  - **OpenRGB**: Direct control via OpenRGB for synchronized lighting across all your devices.
  - **SignalRGB**: Native support for SignalRGB with a dedicated plugin.
  - Smooth transitions and reactive effects.
- **🛡️ Safety First**: Triple-tap protection for critical functions like Bootloader reset and EEPROM clearing.
- **📁 Multi-Layer Support**: Optimized layers for Windows, macOS, and dedicated Numpad functionality.

---

## 📦 Firmware Variants

| Firmware Image | Features | USB IDs (VID:PID) |
| :--- | :--- | :--- |
| **Custom Firmware** | QMK, VIA | `342d:e484` |
| **VIA + OpenRGB** | QMK, VIA, OpenRGB | `342d:e484` |
| **VIA + SignalRGB** | QMK, VIA, SignalRGB | `342d:e484` |
| **⭐ VIA + OpenRGB + SignalRGB** | All Features (The Recommended Choice) | `342d:e484` |
| **VIA + All-in-One (ISO)** | All Features for ISO Layout | `342d:e483` |

---

## 🛠️ Usage Guide

### 📂 Layer System Overview

The firmware uses a 6-layer system for maximum flexibility:

1.  **Layer 0 (Base)**: Default Windows layout.
2.  **Layer 1 (Fn)**: Multimedia, lighting controls, and navigation.
3.  **Layer 2 (Options)**: System configurations (Reset, NKRO, SOCD, Mode Toggle).
4.  **Layer 3 (Mac)**: Optimized layout for macOS users.
5.  **Layer 4 (Numpad)**: Integrated Numpad layout on the alpha keys.

### ⌨️ Key Combinations

#### ⚙️ System Controls (Layer 2)
*Access by holding `Fn` + `Right Shift`*

| Action | Shortcut |
| :--- | :--- |
| **Enter Bootloader** | `Triple Tap Q` |
| **Clear EEPROM** | `Triple Tap Z` |
| **Toggle NKRO** | `N` |
| **Toggle SOCD** | `T` |
| **Toggle OpenRGB** | `O` |
| **Toggle SignalRGB** | `S` |
| **Switch to Layer 0** | `1` |
| **Switch to Layer 3 (Mac)** | `3` |
| **Switch to Layer 4 (Numpad)** | `4` |

#### 💡 RGB Modes (Layer 2)
If using the All-in-One firmware:
- Toggle **OpenRGB**: `Fn` + `Right Shift` + `O`
- Toggle **SignalRGB**: `Fn` + `Right Shift` + `S`
- *Note: If both are off, the keyboard reverts to standard QMK RGB effects.*

---

## 📥 Installation

### 1️⃣ Flashing the Firmware
Use your preferred tool (e.g., QMK Toolbox or `wb32-dfu-updater_cli`) to flash the `.hex` file corresponding to your desired configuration.

### 2️⃣ VIA Configuration
To use VIA, you may need to manually load the JSON layout file:
1.  Open [VIA](https://usevia.app/).
2.  Enable the **"Design"** tab in Settings.
3.  Upload `VIA Layout.json` (or `VIA Layout ISO.json`) from the `layouts/` folder.

### 3️⃣ SignalRGB Setup
1.  Copy [`SignalRGB Plugin for RK R75.js`](plugins/SignalRGB%20Plugin%20for%20RK%20R75.js) to:
    `%userprofile%/Documents/WhirlwindFX/Plugins`
2.  Restart SignalRGB.

---

## 🏗️ Compiling from Source

If you wish to build the firmware yourself, use the following QMK command:

```shell
qmk compile -j 0 -kb rk/r75/custom -km via
```
*The `-j 0` flag enables parallel building for faster results.*

---

## ⚠️ Disclaimer
> [!CAUTION]
> This is a custom firmware. While extensively tested, there is always a risk of bricking your device. Use at your own risk.

---

## 🤝 Credits & Thanks
Huge thanks to the original contributors whose work paved the way for this project:
- [@irfanjmdn](https://github.com/irfanjmdn/)
- [@sdk66](https://github.com/sdk66/)
- [@iamdanielv](https://github.com/iamdanielv)

---
*Maintained with ❤️ for the mechanical keyboard community.*
