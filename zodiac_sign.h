#ifndef ZODIAC_SIGN_H
#define ZODIAC_SIGN_H

#ifdef __cplusplus
extern "C" {
#endif

// 星座枚举
typedef enum {
    ZODIAC_ARIES = 1,      // 白羊座 3.21-4.19
    ZODIAC_TAURUS = 2,     // 金牛座 4.20-5.20
    ZODIAC_GEMINI = 3,     // 双子座 5.21-6.21
    ZODIAC_CANCER = 4,     // 巨蟹座 6.22-7.22
    ZODIAC_LEO = 5,        // 狮子座 7.23-8.22
    ZODIAC_VIRGO = 6,      // 处女座 8.23-9.22
    ZODIAC_LIBRA = 7,      // 天秤座 9.23-10.23
    ZODIAC_SCORPIO = 8,    // 天蝎座 10.24-11.22
    ZODIAC_SAGITTARIUS = 9, // 射手座 11.23-12.21
    ZODIAC_CAPRICORN = 10,  // 摩羯座 12.22-1.19
    ZODIAC_AQUARIUS = 11,   // 水瓶座 1.20-2.18
    ZODIAC_PISCES = 12      // 双鱼座 2.19-3.20
} zodiac_sign_t;

// 公共API
zodiac_sign_t zodiac_get_sign(int month, int day);
const char* zodiac_get_name(zodiac_sign_t sign);
int zodiac_init(void);

#ifdef __cplusplus
}
#endif

#endif // ZODIAC_SIGN_H
