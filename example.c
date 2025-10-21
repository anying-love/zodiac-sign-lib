#include "zodiac_sign.h"
#include <stdio.h>

int main() {
    printf("=== 星座判断库演示 ===\n\n");
    
    // 初始化
    zodiac_init();
    
    // 测试几个日期
    int test_dates[][2] = {
        {3, 21}, {4, 20}, {5, 21}, {6, 22}, {7, 23}, {8, 15},
        {9, 23}, {10, 24}, {11, 23}, {12, 25}, {1, 20}, {2, 19}
    };
    
    for (int i = 0; i < 12; i++) {
        int month = test_dates[i][0];
        int day = test_dates[i][1];
        zodiac_sign_t sign = zodiac_get_sign(month, day);
        printf("%2d月%2d日 -> %s\n", month, day, zodiac_get_name(sign));
    }
    
    // 用户输入
    printf("\n请输入生日（月 日，用空格分隔）: ");
    int month, day;
    if (scanf("%d %d", &month, &day) == 2) {
        zodiac_sign_t sign = zodiac_get_sign(month, day);
        printf("您的星座是: %s\n", zodiac_get_name(sign));
    }
    
    return 0;
}
