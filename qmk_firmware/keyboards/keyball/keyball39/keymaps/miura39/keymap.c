/*
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

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "pointing_device_auto_mouse.h" // オートマウスレイヤーの状態を確認するために必要

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_right_ball(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                            KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                            KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  , LSFT_T(KC_LNG2), LT(1,KC_SPC), LT(3,KC_LNG1), KC_BSPC, LT(2,KC_ENT), LSFT_T(KC_LNG2)
  ),

  [1] = LAYOUT_right_ball(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                            KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  , S(KC_INT3), S(KC_8)  ,                           S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL), S(KC_LBRC), S(KC_7) , S(KC_2)  , S(KC_RBRC),                            KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  , TO(2)    , TO(0)    , _______
  ),

  [2] = LAYOUT_right_ball(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                            KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
    S(KC_QUOT), KC_4     , KC_5     , KC_6     , S(KC_SCLN),                          S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     , S(KC_MINS),                          S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  , _______  , _______  , _______
  ),

  [3] = LAYOUT_right_ball(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                            _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                            _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                            CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_right_ball(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [5] = LAYOUT_right_ball(
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  ,                            _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______  , _______
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
      keyball_handle_auto_mouse_layer_change(state);
    #endif
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

// デフォルトでAMLをON
void pointing_device_init_user(void) {
  set_auto_mouse_layer(1); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
  set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

// pointing_device_task_userはマウス動作時に呼ばれる
// ここでオートマウスレイヤーの状態をチェックして、変化した瞬間だけ通知する
bool pointing_device_task_user(report_mouse_t *mouse_report) {
    // 前回のオートマウスレイヤー状態を保存する変数（関数内staticなので呼び出し間で値保持）
    static bool was_auto_mouse_layer_active = false;

    // 現在のオートマウスレイヤー状態を取得
    bool is_auto_mouse_layer_active = is_auto_mouse_active;

    // 状態が変わったときだけ通知を出す
    if (is_auto_mouse_layer_active && !was_auto_mouse_layer_active) {
        // オートマウスレイヤーに入った瞬間
        uprintf("AML_ON\n");
    } else if (!is_auto_mouse_layer_active && was_auto_mouse_layer_active) {
        // オートマウスレイヤーを抜けた瞬間
        uprintf("AML_OFF\n");
    }

    // 今回の状態を次回用に保存しておく
    was_auto_mouse_layer_active = is_auto_mouse_layer_active;

    return true; // trueを返して、通常のマウス処理を続行させる
}
