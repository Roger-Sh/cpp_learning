#include <stdlib.h>
#include <iostream>

namespace t1
{
    union f_2u8
    {
        float f;
        uint8_t u8[2];
    };

    union f_4u8
    {
        float f;
        uint8_t u8[4];
    };

    union int16_uint8
    {
        int16_t _int16;
        uint8_t _u8[2];
    };

    void test_16bit_split()
    {
        // 1 float == 4 uint8
        std::cout << sizeof(float) << " "
                  << sizeof(uint8_t) << " "
                  << std::endl;

        // 如果只用两个uint8 提取 float中的数据，会有信息丢失
        f_2u8 val1;
        val1.f = 2456.3;
        printf("%#X, %#X\n", val1.u8[0], val1.u8[1]);

        // float to uint8[4]
        f_4u8 val2;
        val2.f = 2456.3;
        printf("%#X, %#X, %#X, %#X\n", val2.u8[0], val2.u8[1], val2.u8[2], val2.u8[3]);
        val2.u8[0] = 0XCE; // 修改一个uint8，同时导致f改变
        std::cout << val2.f << std::endl;

        // u16 to u8[2]
        int16_uint8 val3;
        val3._int16 = -3000;
        printf("%#X, %#X\n", val3._u8[0], val3._u8[1]);

        int16_uint8 val4;
        val4._u8[0] = val3._u8[0];  // low 8bit
        val4._u8[1] = val3._u8[1];  // high 8bit
        std::cout << val4._int16 << std::endl;
        printf("%#X, %#X, %#X\n", val4._int16, val4._u8[0], val4._u8[1]);

        // 通过移位操作，比联合体的方式更好，联合体的方式依赖字节序，容易产生bug
        uint8_t lo;
        uint8_t hi;
        lo = (uint8_t)(val4._int16 & 0XFF);
        hi = (uint8_t)((val4._int16 >> 8) & 0XFF);
        printf("%#X, %#X, %#X\n", val4._int16, lo, hi);

        /*
        // 16 bit system  
        uint8_t bytes [sizeof(int)] = 
        {
        ((uint16_t)i >> 0) & 0xFF,  // shift by 0 not needed, of course, just stylistic
        ((uint16_t)i >> 8) & 0xFF,
        };

        // 32 bit system  
        uint8_t bytes [sizeof(int)] = 
        {
        ((uint32_t)i >>  0) & 0xFF,
        ((uint32_t)i >>  8) & 0xFF,
        ((uint32_t)i >> 16) & 0xFF,
        ((uint32_t)i >> 24) & 0xFF,
        };
        */

    }

    void test_hex_print()
    {
        uint16_t a = 360;
        uint16_t b = -360;
        printf("%#X, %#X \n", a, b);
    }
} // namespace t1

int main()
{
    t1::test_16bit_split();
    t1::test_hex_print();

    return 0;
}