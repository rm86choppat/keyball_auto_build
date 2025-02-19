/*
This is the c configuration file for the keymap

Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
//#    define RGBLIGHT_EFFECT_SNAKE
//#    define RGBLIGHT_EFFECT_KNIGHT
//#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
//#    define RGBLIGHT_EFFECT_RGB_TEST
//#    define RGBLIGHT_EFFECT_ALTERNATING
//#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#define TAP_CODE_DELAY 5

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 1

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// 参考URL
// https://mazcon.hatenablog.com/entry/2023/11/10/080000#%E3%83%9E%E3%82%A6%E3%82%B9%E3%82%B9%E3%82%AF%E3%83%AD%E3%83%BC%E3%83%AB%E9%80%9F%E5%BA%A6%E3%83%87%E3%83%95%E3%82%A9%E3%83%AB%E3%83%88%E5%80%A4
#define KEYBALL_CPI_DEFAULT 600 // マウス速度 (default: 500)
#define KEYBALL_SCROLL_DIV_DEFAULT 3 // スクロール速度 (default: 4)