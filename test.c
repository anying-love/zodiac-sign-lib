#include "zodiac_sign.h"
#include <stdio.h>
#include <assert.h>

void test_all_zodiacs() {
    printf("测试所有星座边界...\n");
    
    // 测试每个星座的开始日期
    struct {
        int month, day;
        const char* expected;
    } tests[] = {
        {3, 21, "白羊座"}, {4, 20, "金牛座"}, {5, 21, "双子座"},
        {6, 22, "巨蟹座"}, {7, 23, "狮子座"}, {8, 23, "处女座"},
        {9, 23, "天秤座"}, {10, 24, "天蝎座"}, {11, 23, "射手座"},
        {12, 22, "摩羯座"}, {1, 20, "水瓶座"}, {2, 19, "双鱼座"}
    };
    
    for (int i = 0; i < 12; i++) {
        zodiac_sign_t sign = zodiac_get_sign(tests[i].month, tests[i].day);
        const char* name = zodiac_get_name(sign);
        printf("%d月%d日: %s", tests[i].month, tests[i].day, name);
        assert(strcmp(name, tests[i].expected) == 0);
        printf(" ✓\n");
    }
}

void test_invalid_dates() {
    printf("\n测试无效日期...\n");
    
    // 测试无效日期
    zodiac_sign_t sign;
    
    sign = zodiac_get_sign(0, 1);    // 无效月份
    printf("0月1日: %s", zodiac_get_name(sign));
    
    sign = zodiac_get_sign(13, 1);   // 无效月份
    printf(" 13月1日: %s", zodiac_get_name(sign));
    
    sign = zodiac_get_sign(2, 30);   // 无效日期
    printf(" 2月30日: %s\n", zodiac_get_name(sign));
}

int main() {
    printf("=== 星座库测试 ===\n");
    zodiac_init();
    
    test_all_zodiacs();
    test_invalid_dates();
    
    printf("\n🎉 所有测试通过！\n");
    return 0;
}
