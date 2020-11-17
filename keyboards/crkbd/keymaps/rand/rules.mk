RGB_MATRIX_ENABLE = WS2812
MOUSEKEY_ENABLE = no
OLED_DRIVER_ENABLE = yes
LTO_ENABLE = yes

SRC += oled.c 
       
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
