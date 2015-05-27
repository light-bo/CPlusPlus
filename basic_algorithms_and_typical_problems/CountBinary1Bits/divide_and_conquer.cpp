/*********************************************************************************************************************
* 设原整数值为x，
* 第一步：把x的32个bit分成16组（第32bit和第31bit一组，第30bit和第29bit一组……以此类推），然后将每一组的两bit上的值（因为是二进制数，所以要么是0要么是1）相加并把结果还放在这两bit的位置上，这样，得到结果整数x1，x1的二进制（32bit）可以分为16组，每一组的数值就是原来整数x在那两bit上1的个数。
* 第二步：把第一步得到的结果x1的32bit，分成8组(第32、31、30、29bit一组，第28、27、26、25bit一组……以此类推)，然后每一组的四bit上的值相加并把结果还放在这四bit的位置上，这样，又得到结果整数x2，x2的二进制可以分为8组，每一组的数值就是原来整数x在那四bit上的1的个数。
* ……
* 这样一直分组计算下去，最终，把两个16bit上1的个数相加，得到原来整数x的32bit上1的个数。

===========================================================================
*/

#include <stdio.h>

typedef unsigned int UINT32;
const UINT32 m1  = 0x55555555;  // 01010101010101010101010101010101
const UINT32 m2  = 0x33333333;  // 00110011001100110011001100110011
const UINT32 m4  = 0x0f0f0f0f;  // 00001111000011110000111100001111
const UINT32 m8  = 0x00ff00ff;  // 00000000111111110000000011111111
const UINT32 m16 = 0x0000ffff;  // 00000000000000001111111111111111
const UINT32 h01 = 0x01010101;  // the sum of 256 to the power of 0, 1, 2, 3

/* This is a naive implementation, shown for comparison, and to help in
* understanding the better functions. It uses 20 arithmetic operations
* (shift, add, and). */
int popcount_1(UINT32 x)
{
  x = (x & m1) + ((x >> 1) & m1);
  x = (x & m2) + ((x >> 2) & m2);
  x = (x & m4) + ((x >> 4) & m4);
  x = (x & m8) + ((x >> 8) & m8);
  x = (x & m16) + ((x >> 16) & m16);
  return x;
}