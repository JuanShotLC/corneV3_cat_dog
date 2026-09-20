#pragma once

#define EE_HANDS

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// OLED Configuración
#define OLED_BRIGHTNESS 120
#define OLED_DISABLE_TIMEOUT
#define SPLIT_OLED_ENABLE
#define SPLIT_WPM_ENABLE
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#ifdef RGB_MATRIX_ENABLE
    // Efectos Reactivos (Olas al presionar)
    #define ENABLE_RGB_MATRIX_SPLASH
    #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    #define ENABLE_RGB_MATRIX_MULTISPLASH

    // Efectos continuos clásicos
    #define ENABLE_RGB_MATRIX_BREATHING
    #define ENABLE_RGB_MATRIX_RAINBOW_MOOD
    #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS

    // Control de Velocidad (Por defecto es 128, 60 lo hace más lento y natural)
    #define RGB_MATRIX_ANIMATION_SPEED_DEFAULT 60
#endif
