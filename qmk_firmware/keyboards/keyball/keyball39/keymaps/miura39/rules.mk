RGBLIGHT_ENABLE = yes

OLED_ENABLE = yes

VIA_ENABLE = yes

OS_DETECTION_ENABLE = yes

CONSOLE_ENABLE = no

LTO_ENABLE = yes
EXTRAFLAGS += -flto

# 容量削減
# https://zenn.dev/koron/articles/98324ab760e83a
# スペース・カデット機能を無効化します。スペース・カデットは左右のシフトキーとコントロールキーのタッピングに開閉カッコ(&)を割り当てる機能です。
SPACE_CADET_ENABLE = no
# GRAVE_ESCキーコードを無効化します。GRAVE_ESCキーコードは単体ならばエスケープ、シフトかGUIボタンと一緒に押すと~(GRAVE)を入力できるキーコードです。
GRAVE_ESC_ENABLE = no
# マジックキーコードを無効化します。マジックキーコードはファームウェアを書き換えたりせずに、一部のキーボードの動作を変更する機能です。
MAGIC_ENABLE = no
MUSIC_ENABLE = no