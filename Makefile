CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2

# 默认目标
all: example test

# 编译示例程序
example: zodiac_sign.c example.c
	$(CC) $(CFLAGS) -o $@ $^

# 编译测试程序
test: zodiac_sign.c test.c
	$(CC) $(CFLAGS) -o $@ $^

# 编译静态库
libzodiac.a: zodiac_sign.o
	ar rcs $@ $^

zodiac_sign.o: zodiac_sign.c zodiac_sign.h
	$(CC) $(CFLAGS) -c zodiac_sign.c

# 编译动态库
libzodiac.so: zodiac_sign.c
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $<

# 运行示例
run-example: example
	./example

# 运行测试
run-test: test
	./test

# 清理
clean:
	rm -f *.o example test libzodiac.a libzodiac.so

# 安装到系统（可选）
install: libzodiac.a zodiac_sign.h
	sudo cp libzodiac.a /usr/local/lib/
	sudo cp zodiac_sign.h /usr/local/include/
	sudo ldconfig

.PHONY: all clean run-example run-test install
