#include "oled.h"
#include "stdlib.h" 
#include "delay.h"

/*---------------------ASCII字符集  偏移量32 ------------------------------*/
const unsigned char F6x8[][6] =		
{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
		0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
		0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
		0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
		0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
		0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
		0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
		0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
		0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
		0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
		0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
		0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
		0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
		0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
		0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
		0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
		0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
		0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
		0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
		0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
		0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
		0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
		0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
		0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
		0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
		0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
		0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
		0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
		0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
		0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
		0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
		0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
		0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
		0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
		0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
		0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
		0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
		0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
		0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
		0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
		0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H
		0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
		0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
		0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
		0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
		0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
		0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
		0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
		0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
		0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
		0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
		0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
		0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
		0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
		0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
		0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
		0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
		0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
		0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
		0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
		0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
		0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
		0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
		0x00, 0x40, 0x40, 0x40, 0x40, 0x40,// _
		0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
		0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
		0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
		0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
		0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
		0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
		0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
		0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
		0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
		0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
		0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
		0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
		0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
		0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
		0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
		0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
		0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
		0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
		0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
		0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
		0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
		0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
		0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
		0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
		0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
		0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
		0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
		0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// horiz lines
};
/*-------------------------8*16的点阵----------------------------------------------*/
const unsigned char F8X16[]=	  
{
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,// 0
  0x00,0x00,0x00,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x33,0x30,0x00,0x00,0x00,//! 1
  0x00,0x10,0x0C,0x06,0x10,0x0C,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//" 2
  0x40,0xC0,0x78,0x40,0xC0,0x78,0x40,0x00,0x04,0x3F,0x04,0x04,0x3F,0x04,0x04,0x00,//# 3
  0x00,0x70,0x88,0xFC,0x08,0x30,0x00,0x00,0x00,0x18,0x20,0xFF,0x21,0x1E,0x00,0x00,//$ 4
  0xF0,0x08,0xF0,0x00,0xE0,0x18,0x00,0x00,0x00,0x21,0x1C,0x03,0x1E,0x21,0x1E,0x00,//% 5
  0x00,0xF0,0x08,0x88,0x70,0x00,0x00,0x00,0x1E,0x21,0x23,0x24,0x19,0x27,0x21,0x10,//& 6
  0x10,0x16,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//' 7
  0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00,0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00,//( 8
  0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00,0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00,//) 9
  0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00,0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00,//* 10
  0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x1F,0x01,0x01,0x01,0x00,//+ 11
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xB0,0x70,0x00,0x00,0x00,0x00,0x00,//, 12
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x01,//- 13
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,//. 14
  0x00,0x00,0x00,0x00,0x80,0x60,0x18,0x04,0x00,0x60,0x18,0x06,0x01,0x00,0x00,0x00,/// 15
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x0F,0x10,0x20,0x20,0x10,0x0F,0x00,//0 16
  0x00,0x10,0x10,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//1 17
  0x00,0x70,0x08,0x08,0x08,0x88,0x70,0x00,0x00,0x30,0x28,0x24,0x22,0x21,0x30,0x00,//2 18
  0x00,0x30,0x08,0x88,0x88,0x48,0x30,0x00,0x00,0x18,0x20,0x20,0x20,0x11,0x0E,0x00,//3 19
  0x00,0x00,0xC0,0x20,0x10,0xF8,0x00,0x00,0x00,0x07,0x04,0x24,0x24,0x3F,0x24,0x00,//4 20
  0x00,0xF8,0x08,0x88,0x88,0x08,0x08,0x00,0x00,0x19,0x21,0x20,0x20,0x11,0x0E,0x00,//5 21
  0x00,0xE0,0x10,0x88,0x88,0x18,0x00,0x00,0x00,0x0F,0x11,0x20,0x20,0x11,0x0E,0x00,//6 22
  0x00,0x38,0x08,0x08,0xC8,0x38,0x08,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,//7 23
  0x00,0x70,0x88,0x08,0x08,0x88,0x70,0x00,0x00,0x1C,0x22,0x21,0x21,0x22,0x1C,0x00,//8 24
  0x00,0xE0,0x10,0x08,0x08,0x10,0xE0,0x00,0x00,0x00,0x31,0x22,0x22,0x11,0x0F,0x00,//9 25
  0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,//: 26
  0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0x00,0x00,0x00,//; 27
  0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00,//< 28
  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x00,//= 29
  0x00,0x08,0x10,0x20,0x40,0x80,0x00,0x00,0x00,0x20,0x10,0x08,0x04,0x02,0x01,0x00,//> 30
  0x00,0x70,0x48,0x08,0x08,0x08,0xF0,0x00,0x00,0x00,0x00,0x30,0x36,0x01,0x00,0x00,//? 31
  0xC0,0x30,0xC8,0x28,0xE8,0x10,0xE0,0x00,0x07,0x18,0x27,0x24,0x23,0x14,0x0B,0x00,//@ 32
  0x00,0x00,0xC0,0x38,0xE0,0x00,0x00,0x00,0x20,0x3C,0x23,0x02,0x02,0x27,0x38,0x20,//A 33
  0x08,0xF8,0x88,0x88,0x88,0x70,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x11,0x0E,0x00,//B 34
  0xC0,0x30,0x08,0x08,0x08,0x08,0x38,0x00,0x07,0x18,0x20,0x20,0x20,0x10,0x08,0x00,//C 35
  0x08,0xF8,0x08,0x08,0x08,0x10,0xE0,0x00,0x20,0x3F,0x20,0x20,0x20,0x10,0x0F,0x00,//D 36
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x20,0x23,0x20,0x18,0x00,//E 37
  0x08,0xF8,0x88,0x88,0xE8,0x08,0x10,0x00,0x20,0x3F,0x20,0x00,0x03,0x00,0x00,0x00,//F 38
  0xC0,0x30,0x08,0x08,0x08,0x38,0x00,0x00,0x07,0x18,0x20,0x20,0x22,0x1E,0x02,0x00,//G 39
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x20,0x3F,0x21,0x01,0x01,0x21,0x3F,0x20,//H 40
  0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//I 41
  0x00,0x00,0x08,0x08,0xF8,0x08,0x08,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,0x00,//J 42
  0x08,0xF8,0x88,0xC0,0x28,0x18,0x08,0x00,0x20,0x3F,0x20,0x01,0x26,0x38,0x20,0x00,//K 43
  0x08,0xF8,0x08,0x00,0x00,0x00,0x00,0x00,0x20,0x3F,0x20,0x20,0x20,0x20,0x30,0x00,//L 44
  0x08,0xF8,0xF8,0x00,0xF8,0xF8,0x08,0x00,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x20,0x00,//M 45
  0x08,0xF8,0x30,0xC0,0x00,0x08,0xF8,0x08,0x20,0x3F,0x20,0x00,0x07,0x18,0x3F,0x00,//N 46
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x10,0x20,0x20,0x20,0x10,0x0F,0x00,//O 47
  0x08,0xF8,0x08,0x08,0x08,0x08,0xF0,0x00,0x20,0x3F,0x21,0x01,0x01,0x01,0x00,0x00,//P 48
  0xE0,0x10,0x08,0x08,0x08,0x10,0xE0,0x00,0x0F,0x18,0x24,0x24,0x38,0x50,0x4F,0x00,//Q 49
  0x08,0xF8,0x88,0x88,0x88,0x88,0x70,0x00,0x20,0x3F,0x20,0x00,0x03,0x0C,0x30,0x20,//R 50
  0x00,0x70,0x88,0x08,0x08,0x08,0x38,0x00,0x00,0x38,0x20,0x21,0x21,0x22,0x1C,0x00,//S 51
  0x18,0x08,0x08,0xF8,0x08,0x08,0x18,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//T 52
  0x08,0xF8,0x08,0x00,0x00,0x08,0xF8,0x08,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//U 53
  0x08,0x78,0x88,0x00,0x00,0xC8,0x38,0x08,0x00,0x00,0x07,0x38,0x0E,0x01,0x00,0x00,//V 54
  0xF8,0x08,0x00,0xF8,0x00,0x08,0xF8,0x00,0x03,0x3C,0x07,0x00,0x07,0x3C,0x03,0x00,//W 55
  0x08,0x18,0x68,0x80,0x80,0x68,0x18,0x08,0x20,0x30,0x2C,0x03,0x03,0x2C,0x30,0x20,//X 56
  0x08,0x38,0xC8,0x00,0xC8,0x38,0x08,0x00,0x00,0x00,0x20,0x3F,0x20,0x00,0x00,0x00,//Y 57
  0x10,0x08,0x08,0x08,0xC8,0x38,0x08,0x00,0x20,0x38,0x26,0x21,0x20,0x20,0x18,0x00,//Z 58
  0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00,0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00,//[ 59
  0x00,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x06,0x38,0xC0,0x00,//\ 60
  0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00,//] 61
  0x00,0x00,0x04,0x02,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//^ 62
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,//_ 63
  0x00,0x02,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//` 64
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x19,0x24,0x22,0x22,0x22,0x3F,0x20,//a 65
  0x08,0xF8,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x3F,0x11,0x20,0x20,0x11,0x0E,0x00,//b 66
  0x00,0x00,0x00,0x80,0x80,0x80,0x00,0x00,0x00,0x0E,0x11,0x20,0x20,0x20,0x11,0x00,//c 67
  0x00,0x00,0x00,0x80,0x80,0x88,0xF8,0x00,0x00,0x0E,0x11,0x20,0x20,0x10,0x3F,0x20,//d 68
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x22,0x22,0x22,0x22,0x13,0x00,//e 69
  0x00,0x80,0x80,0xF0,0x88,0x88,0x88,0x18,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//f 70
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x6B,0x94,0x94,0x94,0x93,0x60,0x00,//g 71
  0x08,0xF8,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//h 72
  0x00,0x80,0x98,0x98,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//i 73
  0x00,0x00,0x00,0x80,0x98,0x98,0x00,0x00,0x00,0xC0,0x80,0x80,0x80,0x7F,0x00,0x00,//j 74
  0x08,0xF8,0x00,0x00,0x80,0x80,0x80,0x00,0x20,0x3F,0x24,0x02,0x2D,0x30,0x20,0x00,//k 75
  0x00,0x08,0x08,0xF8,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x3F,0x20,0x20,0x00,0x00,//l 76
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x20,0x3F,0x20,0x00,0x3F,0x20,0x00,0x3F,//m 77
  0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x3F,0x21,0x00,0x00,0x20,0x3F,0x20,//n 78
  0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x1F,0x20,0x20,0x20,0x20,0x1F,0x00,//o 79
  0x80,0x80,0x00,0x80,0x80,0x00,0x00,0x00,0x80,0xFF,0xA1,0x20,0x20,0x11,0x0E,0x00,//p 80
  0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x0E,0x11,0x20,0x20,0xA0,0xFF,0x80,//q 81
  0x80,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x20,0x20,0x3F,0x21,0x20,0x00,0x01,0x00,//r 82
  0x00,0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x33,0x24,0x24,0x24,0x24,0x19,0x00,//s 83
  0x00,0x80,0x80,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x20,0x00,0x00,//t 84
  0x80,0x80,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x1F,0x20,0x20,0x20,0x10,0x3F,0x20,//u 85
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x00,0x01,0x0E,0x30,0x08,0x06,0x01,0x00,//v 86
  0x80,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x0F,0x30,0x0C,0x03,0x0C,0x30,0x0F,0x00,//w 87
  0x00,0x80,0x80,0x00,0x80,0x80,0x80,0x00,0x00,0x20,0x31,0x2E,0x0E,0x31,0x20,0x00,//x 88
  0x80,0x80,0x80,0x00,0x00,0x80,0x80,0x80,0x80,0x81,0x8E,0x70,0x18,0x06,0x01,0x00,//y 89
  0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x21,0x30,0x2C,0x22,0x21,0x30,0x00,//z 90
  0x00,0x00,0x00,0x00,0x80,0x7C,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x3F,0x40,0x40,//{ 91
  0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,//| 92
  0x00,0x02,0x02,0x7C,0x80,0x00,0x00,0x00,0x00,0x40,0x40,0x3F,0x00,0x00,0x00,0x00,//} 93
  0x00,0x06,0x01,0x01,0x02,0x02,0x04,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,//~ 94
};
/*-------------------------汉字取模点阵-------------------------------------*/
char Hzk[][32]={

{0x00,0x00,0x3F,0xF0,0x20,0x10,0x20,0x10,0x28,0x50,0x24,0x50,0x22,0x90,0x22,0x90},
{0x21,0x10,0x21,0x10,0x22,0x90,0x22,0x92,0x24,0x4A,0x48,0x4A,0x40,0x06,0x80,0x02},/*"?",0*/

{0x40,0x40,0x40,0x5F,0x55,0x55,0x55,0x75,0x55,0x55,0x55,0x5F,0x40,0x40,0x40,0x00},
{0x00,0x40,0x20,0x0F,0x09,0x49,0x89,0x79,0x09,0x09,0x09,0x0F,0x20,0x40,0x00,0x00},/*"景",1*/

{0x00,0xFE,0x02,0x42,0x4A,0xCA,0x4A,0x4A,0xCA,0x4A,0x4A,0x42,0x02,0xFE,0x00,0x00},
{0x00,0xFF,0x40,0x50,0x4C,0x43,0x40,0x40,0x4F,0x50,0x50,0x5C,0x40,0xFF,0x00,0x00},/*"园",2*/

{0x00,0x00,0xF8,0x88,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x88,0xF8,0x00,0x00,0x00},
{0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x7F,0x88,0x88,0x88,0x88,0x9F,0x80,0xF0,0x00},/*"电",3*/

{0x80,0x82,0x82,0x82,0x82,0x82,0x82,0xE2,0xA2,0x92,0x8A,0x86,0x82,0x80,0x80,0x00},
{0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"子",4*/

{0x24,0x24,0xA4,0xFE,0xA3,0x22,0x00,0x22,0xCC,0x00,0x00,0xFF,0x00,0x00,0x00,0x00},
{0x08,0x06,0x01,0xFF,0x00,0x01,0x04,0x04,0x04,0x04,0x04,0xFF,0x02,0x02,0x02,0x00},/*"科",5*/

{0x10,0x10,0x10,0xFF,0x10,0x90,0x08,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x08,0x00},
{0x04,0x44,0x82,0x7F,0x01,0x80,0x80,0x40,0x43,0x2C,0x10,0x28,0x46,0x81,0x80,0x00},/*"技",6*/

};			   

void OLED_WR_Byte(u8 dat,u8 cmd)   //向OLED写入一个字节 cmd:数据/命令标志 0,表示命令;1,表示数据; dat:要写入的数据/命令
{	
	u8 i;			  
	if(cmd)
	  OLED_DC_Set();
	else 
	  OLED_DC_Clr();		  
	OLED_CS_Clr();
	for(i=0;i<8;i++)
	{			  
		OLED_SCLK_Clr();
		if(dat&0x80)
		   OLED_SDIN_Set();
		else 
		   OLED_SDIN_Clr();
		OLED_SCLK_Set();
		dat<<=1;   
	}				 		  
	OLED_CS_Set();
	OLED_DC_Set();   	  
} 

void OLED_Set_Pos(unsigned char x, unsigned char y)  //设置坐标点
{ 
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f)|0x01,OLED_CMD); 
}
/*----------------------功能描述 清屏函数-------------------*/	
void OLED_Clear(void)  
{  
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //设置页地址（0~7）
		OLED_WR_Byte (0x00,OLED_CMD);      //设置显示位置—列低地址
		OLED_WR_Byte (0x10,OLED_CMD);      //设置显示位置—列高地址   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //更新显示
}
/*---------------------功能描述 显示一个6x8大小的字符-------------------*/	
void OLED_P6x8Char(u8 x,u8 y,u8 chr)
{
	unsigned char c=0,i=0;	
	c=chr-' ';//得到偏移后的值			
	if(x>=128){x=0;y=y+1;}
		
	OLED_Set_Pos(x,y);
	for(i=0;i<6;i++)
		OLED_WR_Byte(F6x8[c][i],OLED_DATA);				
}
/*----------------------功能描述 显示一个8x16大小的字符-------------------*/	
void OLED_P8x16Char(u8 x,u8 y,u8 chr)
{      	
	unsigned char c=0,i=0;	
	c=chr-' ';					//得到偏移后的值			
	if(x>=128){x=0;y=y+2;}

	OLED_Set_Pos(x,y);	
	for(i=0;i<8;i++)
		OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
	OLED_Set_Pos(x,y+1);
	for(i=0;i<8;i++)
		OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
			
}
/*----------------------功能描述 显示一个6x8大小的字符串-------------------*/	
void OLED_P6x8Str(u8 x,u8 y,u8 ch[])
{
	u8 c=0,i=0,j=0;      
	while (ch[j]!='\0')
	{    
		c =ch[j]-32;
		if(x>128)
		{
			x=0;
			y++;
		}
		OLED_Set_Pos(x,y);    
		for(i=0;i<6;i++)
		{     
			OLED_WR_Byte(F6x8[c][i],OLED_DATA);  
		}
		x+=6;
		j++;
	}
}
/*----------------------功能描述 显示一个8x16大小的字符串-------------------*/		
void OLED_P8x16Str(u8 x,u8 y,u8 *chr)
{
	unsigned char j=0;
	while (chr[j]!='\0')
	{
			OLED_P8x16Char(x,y,chr[j]);
			x+=8;
			if(x>120){x=0;y+=2;}
			j++;
	}
}

/*----------------------功能描述 显示汉字(字模中需要有此函数)------------------*/		
void OLED_ShowCHinese(u8 x,u8 y,u8 no)
{      			    
	u8 t,adder=0;
	OLED_Set_Pos(x,y);	
    for(t=0;t<16;t++)
		{
				OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);
				adder+=1;
     }	
		OLED_Set_Pos(x,y+1);	
    for(t=0;t<16;t++)
			{	
				OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
				adder+=1;
      }					
}
/*----------------------功能描述 根据变量数值大小转换为多位数显示(6x8)-------------------*/		
void OLED_P6x8Value(unsigned short x, unsigned short y, int data)
{
	unsigned short val[5],k; 
	if(data < 0)
	{
		OLED_P6x8Char(x,y,'-');
		data = - data;	
	}
	else
	{
		OLED_P6x8Char(x,y,' ');
	}
	if(data>100000)
	{
		OLED_P6x8Str(x,y,"Over!!");
	}
	else if(data >1000)
	{
		val[0] = (data%100000)/10000;
		val[1] = (data%10000)/1000;
		val[2] = (data%1000)/100;
		val[3] = (data%100)/10;
		val[4] = data%10;
		if(val[0]!=0) 	OLED_P6x8Char(x+6,y,val[0]+48);  else OLED_P6x8Char(x+6,y,' ');
		if(val[1]!=0||(val[1]==0&&val[0]!=0)) OLED_P6x8Char(x+12,y,val[1]+48);  else OLED_P6x8Char(x+12,y,' ');
		
			for(k=2;k<5;k++)
			{
				OLED_P6x8Char(x+6*(k+1),y,val[k]+48); 
			}
	}
	else
	{
		val[0] = (data%1000)/100;
		val[1] = (data%100)/10;
		val[2] = data%10;
		OLED_P6x8Char(x+6,y,' ');
		OLED_P6x8Char(x+12,y,' ');
		if(val[0]!=0) OLED_P6x8Char(x+18,y,val[0]+48);  else OLED_P6x8Char(x+18,y,' ');
		if(val[1]!=0||(val[1]==0&&val[0]!=0))OLED_P6x8Char(x+24,y,val[1]+48); else OLED_P6x8Char(x+24,y,' ');
		OLED_P6x8Char(x+30,y,val[2]+48);
		
	}		
}
/*----------------------功能描述 根据变量数值大小转换为多位数显示(8x16)-------------------*/		
void OLED_P8x16Value(unsigned short x, unsigned short y,int data)
{
	unsigned short val[5],k; 
	if(data < 0)
	{
		OLED_P8x16Char(x,y,'-');
		data = - data;	
	}
	else
	{
		OLED_P8x16Char(x,y,' ');
	}
	if(data>100000)
	{
		OLED_P8x16Str(x,y,"Over!!");
	}
	else if(data >1000)
	{
		val[0] = (data%100000)/10000;
		val[1] = (data%10000)/1000;
		val[2] = (data%1000)/100;
		val[3] = (data%100)/10;
		val[4] = data%10;
		if(val[0]!=0) 	OLED_P8x16Char(x+8,y,val[0]+48); else OLED_P8x16Char(x+8,y,' ');
		if(val[1]!=0||(val[1]==0&&val[1]!=0)) OLED_P8x16Char(x+16,y,val[1]+48); else OLED_P8x16Char(x+16,y,' ');
		
			for(k=2;k<5;k++)
			{
				OLED_P8x16Char(x+8*(k+1),y,val[k]+48); 
			}
	}
	else
	{
		val[0] = (data%1000)/100;
		val[1] = (data%100)/10;
		val[2] = data%10;
		OLED_P8x16Char(x+8,y,' ');
		OLED_P8x16Char(x+16,y,' ');
		if(val[0]!=0) OLED_P8x16Char(x+24,y,val[0]+48); else OLED_P8x16Char(x+24,y,' ');
		if(val[1]!=0||(val[1]==0&&val[1]!=0))OLED_P8x16Char(x+32,y,val[1]+48); else OLED_P8x16Char(x+32,y,' ');
		OLED_P8x16Char(x+40,y,val[2]+48);
		
	}		
}
/*------------功能描述：显示显示BMP图片128×64起始点坐标(x,y),x的范围0～127，y为页的范围0～7------------*/
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{ 	
 unsigned int j=0;
 unsigned char x,y;
  
  if(y1%8==0) y=y1/8;      
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {      
	    	OLED_WR_Byte(BMP[j++],OLED_DATA);	    	
	    }
	}
} 
/*----------------------功能描述：OLED初始化函数--------------------*/				    
void OLED_Init(void)
{ 	
 	GPIO_InitTypeDef  GPIO_InitStructure;
 	
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG, ENABLE);	 //使能PC,D,G端口时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8;	 //PD3,PD6推挽输出  
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//速度50MHz
 	GPIO_Init(GPIOG, &GPIO_InitStructure);	  //初始化GPIOD3,6
 	GPIO_SetBits(GPIOG,GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8);	//PD3,PD6 输出高
 
  OLED_RST_Set();
	delay_ms(100);
	OLED_RST_Clr();
	delay_ms(100);
	OLED_RST_Set(); 
					  
	OLED_WR_Byte(0xAE,OLED_CMD);//--turn off oled panel
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0x81,OLED_CMD);//--set contrast control register
	OLED_WR_Byte(0xCF,OLED_CMD); // Set SEG Output Current Brightness
	OLED_WR_Byte(0xA1,OLED_CMD);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	OLED_WR_Byte(0xC8,OLED_CMD);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	OLED_WR_Byte(0xA6,OLED_CMD);//--set normal display
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3f,OLED_CMD);//--1/64 duty
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WR_Byte(0x00,OLED_CMD);//-not offset
	OLED_WR_Byte(0xd5,OLED_CMD);//--set display clock divide ratio/oscillator frequency
	OLED_WR_Byte(0x80,OLED_CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WR_Byte(0xD9,OLED_CMD);//--set pre-charge period
	OLED_WR_Byte(0xF1,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDA,OLED_CMD);//--set com pins hardware configuration
	OLED_WR_Byte(0x12,OLED_CMD);
	OLED_WR_Byte(0xDB,OLED_CMD);//--set vcomh
	OLED_WR_Byte(0x40,OLED_CMD);//Set VCOM Deselect Level
	OLED_WR_Byte(0x20,OLED_CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WR_Byte(0x02,OLED_CMD);//
	OLED_WR_Byte(0x8D,OLED_CMD);//--set Charge Pump enable/disable
	OLED_WR_Byte(0x14,OLED_CMD);//--set(0x10) disable
	OLED_WR_Byte(0xA4,OLED_CMD);// Disable Entire Display On (0xa4/0xa5)
	OLED_WR_Byte(0xA6,OLED_CMD);// Disable Inverse Display On (0xa6/a7) 
	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
	
	OLED_WR_Byte(0xAF,OLED_CMD); /*display ON*/ 
	OLED_Clear();
	OLED_Set_Pos(0,0); 	
}  

