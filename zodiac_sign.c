#include "zodiac_sign.h"
#include <stdio.h>
#include <string.h>

// 星座名称数组
static const char* zodiac_names[] = {
    "", "白羊座", "金牛座", "双子座", "巨蟹座", "狮子座", "处女座",
    "天秤座", "天蝎座", "射手座", "摩羯座", "水瓶座", "双鱼座"
};

// 星座日期范围表（每个星座的开始日期）
static const int zodiac_start_dates[][2] = {
    {3, 21},  // 白羊座开始
    {4, 20},  // 金牛座开始
    {5, 21},  // 双子座开始
    {6, 22},  // 巨蟹座开始
    {7, 23},  // 狮子座开始
    {8, 23},  // 处女座开始
    {9, 23},  // 天秤座开始
    {10, 24}, // 天蝎座开始
    {11, 23}, // 射手座开始
    {12, 22}, // 摩羯座开始
    {1, 20},  // 水瓶座开始
    {2, 19}   // 双鱼座开始
};

// 验证日期有效性
static int is_valid_date(int month, int day) {
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;
    
    // 月份天数验证
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;
    if (month == 2 && day > 29) return 0;
    
    return 1;
}

// 初始化库
int zodiac_init(void) {
    return 0; // 无需特殊初始化
}

// 获取星座
zodiac_sign_t zodiac_get_sign(int month, int day) {
    if (!is_valid_date(month, day)) {
        return ZODIAC_ARIES; // 默认返回白羊座
    }
    
    // 特殊处理摩羯座（跨年）
    if ((month == 12 && day >= 22) || (month == 1 && day <= 19)) {
        return ZODIAC_CAPRICORN;
    }
    
    // 其他星座判断
    for (int i = 0; i < 11; i++) {
        int start_month = zodiac_start_dates[i][0];
        int start_day = zodiac_start_dates[i][1];
        int next_month = zodiac_start_dates[i + 1][0];
        int next_day = zodiac_start_dates[i + 1][1];
        
        if ((month == start_month && day >= start_day) ||
            (month == next_month && day < next_day)) {
            return (zodiac_sign_t)(i + 1);
        }
    }
    
    return ZODIAC_ARIES;
}

// 获取星座名称
const char* zodiac_get_name(zodiac_sign_t sign) {
    if (sign < ZODIAC_ARIES || sign > ZODIAC_PISCES) {
        return "未知星座";
    }
    return zodiac_names[sign];
}
