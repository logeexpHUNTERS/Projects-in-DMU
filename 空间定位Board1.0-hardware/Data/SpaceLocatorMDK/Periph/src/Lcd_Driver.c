#include "Lcd_Driver.h"
#include "Sys_Delay.h"
//16位BMP 40X40 QQ图像取模数据
//Image2LCD取模选项设置
//水平扫描
//16位
//40X40
//不包含图像头数据
//自左至右
//自顶至底
//低位在前
const unsigned char Image[3200] = { /*0X00,0X10,0X28,0X00,0X28,0X00,0X01,0X1B,*/
0XDB,0XDE,0X5D,0XEF,0X5D,0XEF,0X7D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,
0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0XBE,0XF7,
0XFF,0XFF,0XDE,0XFF,0X38,0XC6,0X92,0X8C,0X8E,0X6B,0X6E,0X6B,0X10,0X7C,0X96,0XAD,
0X3C,0XE7,0XFF,0XFF,0XFF,0XFF,0X7D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,
0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,0X5D,0XEF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X5D,0XEF,
0X15,0X9D,0X4F,0X63,0X6C,0X42,0X0A,0X32,0X88,0X29,0X46,0X19,0X25,0X19,0X45,0X21,
0XE8,0X31,0X8E,0X6B,0X18,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,0XF5,0X9C,0X0F,0X53,
0X10,0X4B,0X51,0X53,0X0F,0X4B,0X6C,0X3A,0XE9,0X31,0X67,0X21,0X25,0X19,0XE4,0X10,
0XA3,0X08,0X62,0X00,0X83,0X08,0X8A,0X4A,0X59,0XC6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X1C,0XE7,0X4F,0X5B,0XB3,0X63,0XB8,0X7C,
0XF5,0X63,0X11,0X43,0X4D,0X32,0XEA,0X29,0X88,0X21,0X26,0X19,0X05,0X19,0X05,0X19,
0X04,0X11,0X04,0X11,0XE4,0X10,0X83,0X00,0XA3,0X08,0X72,0X8C,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDB,0XDE,0X4B,0X3A,0XF0,0X42,0X35,0X6C,0X54,0X4B,
0XB1,0X32,0X2E,0X2A,0XEB,0X21,0XA9,0X21,0X67,0X19,0X05,0X19,0X04,0X11,0X04,0X11,
0X04,0X11,0X04,0X11,0X04,0X11,0X05,0X19,0XE4,0X10,0X42,0X00,0XAF,0X73,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X5D,0XEF,0X09,0X32,0X4C,0X32,0X10,0X4B,0X8F,0X32,0X4F,0X2A,
0X2E,0X2A,0XCC,0X19,0X89,0X19,0X89,0X21,0X47,0X19,0X05,0X19,0X04,0X11,0X04,0X11,
0XC4,0X10,0XC4,0X10,0X04,0X11,0X04,0X11,0X04,0X11,0XE4,0X10,0X42,0X00,0X31,0X84,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XEC,0X52,0X47,0X19,0X4C,0X32,0X0B,0X2A,0XEC,0X21,0XEC,0X21,
0X0C,0X22,0X91,0X5B,0XEE,0X4A,0X06,0X11,0X26,0X19,0X04,0X19,0XE4,0X10,0XE4,0X10,
0XA7,0X29,0X66,0X21,0XA3,0X08,0X05,0X19,0X04,0X11,0X04,0X11,0XE4,0X10,0X82,0X00,
0XF7,0XBD,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X35,0XA5,0X83,0X08,0X88,0X21,0X88,0X21,0X89,0X21,0XAA,0X21,0X8A,0X21,
0X6B,0X42,0X71,0X8C,0XFF,0XFF,0X72,0X8C,0X83,0X08,0X04,0X11,0XC4,0X08,0X29,0X42,
0XFB,0XDE,0X5D,0XEF,0XEC,0X5A,0X83,0X08,0X04,0X11,0X04,0X11,0X04,0X11,0X83,0X08,
0XE8,0X31,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XBE,0XF7,0XC7,0X31,0XC4,0X10,0X25,0X19,0X26,0X19,0X47,0X19,0X47,0X19,0XA8,0X29,
0X8A,0X52,0X28,0X4A,0X55,0XAD,0XFF,0XFF,0XE8,0X31,0XA3,0X08,0X05,0X19,0X4D,0X6B,
0X4D,0X6B,0XFF,0XFF,0X7D,0XEF,0X45,0X21,0XC4,0X10,0X04,0X11,0X04,0X11,0X04,0X11,
0X62,0X00,0X76,0XAD,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X96,0XB5,0X62,0X00,0X04,0X11,0X04,0X19,0X05,0X11,0X05,0X19,0XC4,0X08,0X8B,0X4A,
0XB6,0XB5,0X5D,0XEF,0XF7,0XBD,0XFF,0XFF,0X8E,0X6B,0X62,0X00,0X29,0X42,0XAA,0X5A,
0X08,0X42,0XFF,0XFF,0XFF,0XFF,0XCC,0X52,0X83,0X08,0X04,0X11,0X04,0X11,0X04,0X11,
0XA3,0X08,0XAD,0X52,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XBE,0XF7,0XFF,0XFF,0XDF,0XFF,0XDB,0XDE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X4E,0X63,0X62,0X00,0X04,0X11,0X04,0X11,0X04,0X11,0XE4,0X10,0X62,0X00,0X8E,0X63,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XCF,0X73,0X01,0X00,0XF3,0X9C,0X2C,0X63,
0X96,0XB5,0XFF,0XFF,0XFF,0XFF,0X2D,0X5B,0X83,0X00,0X04,0X11,0X04,0X11,0X04,0X11,
0XE4,0X10,0X67,0X21,0X3D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XB7,0XB5,0X76,0XAD,0X7D,0XEF,0XCB,0X52,0XB3,0X94,0XFF,0XFF,0XFF,0XFF,0XDF,0XFF,
0XE8,0X31,0XA3,0X08,0X04,0X11,0X04,0X11,0X04,0X11,0X04,0X11,0XA3,0X08,0X49,0X42,
0XFF,0XF7,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0X6A,0X4A,0X01,0X00,0X72,0X84,0XFF,0XFF,
0XFF,0XFF,0XFF,0XF7,0XDF,0XEF,0X09,0X3A,0XA3,0X08,0X04,0X11,0X04,0X11,0X04,0X11,
0X04,0X11,0X05,0X11,0X18,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XF0,0X7B,0X62,0X00,0XE8,0X31,0XC7,0X31,0X41,0X00,0X35,0XA5,0XFF,0XFF,0X5D,0XEF,
0X46,0X21,0XC4,0X10,0X04,0X11,0X04,0X11,0X04,0X11,0X04,0X11,0XE4,0X10,0XA3,0X08,
0X76,0X9D,0XFF,0XF7,0XFF,0XFF,0XB7,0XAD,0XA3,0X08,0XA3,0X08,0XC7,0X31,0X9E,0XE7,
0XFF,0XF7,0XFF,0XF7,0X76,0XA5,0XA3,0X08,0XE4,0X10,0X04,0X11,0X04,0X11,0X04,0X11,
0X05,0X11,0X05,0X11,0X35,0XA5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XDB,0XDE,0XA7,0X29,0X83,0X00,0XC4,0X10,0XC4,0X10,0XC4,0X10,0X1C,0XE7,0X9E,0XEF,
0X05,0X11,0XE4,0X10,0X04,0X11,0X04,0X11,0X04,0X11,0X04,0X11,0X04,0X19,0XC4,0X08,
0XE5,0X10,0XD1,0X6B,0XD1,0X6B,0XC5,0X08,0X64,0X00,0XA5,0X08,0X43,0X00,0X2B,0X32,
0X77,0X9D,0XB3,0X84,0X25,0X19,0XC4,0X10,0X04,0X11,0X04,0X11,0X04,0X11,0X04,0X11,
0X25,0X19,0X26,0X09,0X35,0X9D,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XAF,0X73,0X62,0X00,0X04,0X19,0X05,0X19,0X82,0X00,0X0D,0X5B,0X8E,0X9B,
0X62,0X10,0X05,0X11,0X04,0X11,0X04,0X11,0X04,0X19,0XE4,0X10,0X85,0X00,0X05,0X11,
0XC4,0X39,0X81,0X5A,0X40,0X7B,0X22,0X9C,0X43,0XAC,0X03,0XA4,0X83,0X9B,0X82,0X72,
0X82,0X49,0XC2,0X18,0XA4,0X00,0XC5,0X00,0XE4,0X10,0X04,0X19,0X04,0X11,0X05,0X19,
0X47,0X19,0X67,0X11,0XEC,0X5A,0XBE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XDF,0XFF,0XDB,0XD6,0XC4,0X10,0XE4,0X10,0X04,0X11,0X05,0X11,0XA4,0X18,0X01,0XC0,
0X83,0X88,0XE4,0X00,0X05,0X19,0X04,0X19,0XC5,0X08,0X44,0X21,0X43,0X83,0X23,0XD5,
0X42,0XFE,0XE4,0XFE,0X27,0XFF,0X07,0XFF,0XA4,0XFE,0X64,0XFE,0X03,0XFE,0XA3,0XFD,
0XE2,0XFC,0X42,0XEC,0X83,0XB3,0X24,0X62,0XE5,0X10,0XC4,0X08,0X04,0X19,0X26,0X19,
0XA8,0X19,0X87,0X21,0X00,0X90,0XD3,0XBC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XF0,0X7B,0X42,0X00,0X05,0X19,0X05,0X11,0X83,0X28,0X01,0XD0,
0X44,0XF8,0XA3,0X48,0XE4,0X00,0XC5,0X08,0X44,0X5A,0X02,0XED,0XE2,0XFD,0X02,0XFE,
0X66,0XFE,0X74,0XFF,0XB8,0XFF,0X73,0XFF,0XE7,0XF6,0XA6,0XF6,0X45,0XF6,0XA4,0XF5,
0XC3,0XFC,0X62,0XFC,0XC2,0XFC,0XC2,0XFC,0XE3,0XCB,0XC4,0X49,0X06,0X11,0X88,0X19,
0X87,0X01,0XA4,0X90,0X01,0XF8,0XEC,0X9A,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0X9E,0XF7,0XE8,0X31,0X83,0X00,0X05,0X09,0X82,0X40,0X01,0XC0,
0X23,0XF8,0X85,0XF0,0XA3,0X48,0XA4,0X00,0X44,0X5A,0X02,0XFD,0X23,0XCC,0XC2,0XDC,
0X04,0XFE,0X28,0XFE,0X48,0XF6,0X46,0XF6,0X24,0XF6,0XE4,0XF5,0X64,0XFD,0XE3,0XFC,
0X62,0XFC,0XC2,0XFC,0X02,0XE4,0X02,0XDC,0XE2,0XFC,0XA4,0X7A,0X48,0X01,0X67,0X01,
0XC4,0X78,0X24,0XF8,0X02,0XF8,0X84,0XB0,0X7D,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XDB,0XDE,0X25,0X19,0XA3,0X00,0XC4,0X38,0X02,0XE0,
0X22,0XD8,0X44,0XF8,0XA6,0XF8,0XA4,0X78,0X63,0X00,0X43,0X21,0X83,0X72,0X83,0X39,
0X82,0X9B,0X21,0XF5,0X61,0XFD,0X22,0XFD,0XE2,0XFC,0XA2,0XFC,0X42,0XFC,0X42,0XFC,
0X42,0XFC,0X22,0XAB,0X83,0X41,0XC3,0X92,0X04,0X52,0X26,0X01,0X25,0X19,0XA4,0X98,
0X44,0XF8,0X23,0XF8,0X02,0XF8,0XA4,0XD0,0X9E,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9A,0XD6,0X87,0X29,0XA5,0X00,0X43,0XB8,
0X22,0XF8,0X23,0XE0,0X65,0XF8,0XE8,0XF8,0X07,0XC9,0X83,0X48,0X42,0X00,0XA3,0X00,
0X84,0X00,0X63,0X29,0XA2,0X7A,0X62,0XB3,0XA2,0XCB,0X62,0XD3,0X02,0XBB,0X82,0X8A,
0X83,0X39,0XA4,0X00,0XE5,0X00,0XE5,0X00,0XE5,0X08,0XC4,0X60,0X64,0XD8,0X44,0XF8,
0X24,0XF8,0X23,0XF8,0X02,0XF8,0X83,0X88,0XDB,0XC6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X3D,0XE7,0X50,0X5B,0X08,0X31,
0X23,0XE8,0X43,0XF8,0X44,0XF0,0X65,0XF8,0X09,0XF9,0XAB,0XF9,0X89,0XD1,0X06,0X89,
0XA3,0X48,0X42,0X18,0X02,0X00,0X42,0X00,0X61,0X00,0X82,0X00,0X62,0X00,0X62,0X00,
0X83,0X00,0XA3,0X20,0XC4,0X50,0XA5,0X88,0X85,0XD8,0X65,0XF8,0X44,0XF8,0X44,0XF8,
0X23,0XF8,0X23,0XF8,0X03,0XD0,0X82,0X10,0XC7,0X29,0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X6C,0X32,
0XA5,0X38,0X02,0XD8,0X23,0XF8,0X65,0XF8,0X66,0XF8,0XA7,0XF8,0X4A,0XF9,0X0C,0XFA,
0X4D,0XFA,0X4C,0XEA,0X0B,0XD2,0XA9,0XB9,0X68,0XB1,0X47,0XA9,0X27,0XB1,0X07,0XB9,
0X07,0XD1,0XE7,0XE8,0XC7,0XF8,0XA7,0XF8,0X65,0XF8,0X65,0XF8,0X44,0XF8,0X23,0XF8,
0X03,0XF8,0X02,0XD0,0XA3,0X28,0X05,0X09,0XC4,0X08,0XEC,0X5A,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFB,0XDE,0X05,0X19,
0XC4,0X00,0XA7,0X41,0XE6,0XC0,0X03,0XF8,0X86,0XF8,0XA7,0XF8,0X87,0XF8,0X86,0XF8,
0XC7,0XF8,0X29,0XF9,0X8A,0XF9,0XAB,0XF9,0XAB,0XF9,0X8B,0XF9,0X6A,0XF9,0X29,0XF9,
0X08,0XF9,0XC7,0XF8,0XA6,0XF8,0X86,0XF8,0X65,0XF8,0X64,0XF8,0X23,0XF8,0X02,0XF0,
0X06,0XB1,0X25,0X29,0XE4,0X00,0XE4,0X10,0X25,0X19,0X25,0X19,0X14,0X9D,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X96,0XAD,0X62,0X00,
0X82,0X08,0X35,0X95,0XBA,0XCE,0X8B,0XA2,0X44,0XD0,0X25,0XF8,0X87,0XF8,0XA7,0XF8,
0XC7,0XF8,0XA7,0XF8,0X87,0XF8,0X86,0XF8,0X86,0XF8,0X86,0XF8,0X87,0XF8,0XA7,0XF8,
0XA7,0XF8,0XA6,0XF8,0X85,0XF8,0X65,0XF8,0X64,0XF8,0X24,0XF0,0X64,0XB8,0X0D,0X93,
0XBB,0XB6,0XCF,0X63,0X83,0X08,0X04,0X11,0XE4,0X10,0X66,0X21,0X49,0X3A,0X5D,0XEF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XD3,0X94,0X42,0X00,
0XE4,0X10,0XBB,0XCE,0XFF,0XFF,0XBE,0XE7,0X76,0XB5,0XCC,0XAA,0X07,0XC1,0X45,0XE0,
0X45,0XF8,0X46,0XF8,0X66,0XF8,0X86,0XF8,0X86,0XF8,0X86,0XF8,0X86,0XF8,0X65,0XF8,
0X45,0XF8,0X65,0XF8,0X65,0XE8,0X44,0XD0,0X43,0XA8,0X01,0X88,0X82,0X90,0X3C,0XD7,
0XFF,0XEF,0X55,0X95,0X83,0X08,0X04,0X11,0X04,0X11,0X05,0X19,0X46,0X19,0XB3,0X94,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XB3,0X94,0X41,0X00,
0X86,0X21,0X5D,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XDF,0XE7,0X7A,0XC6,0XD3,0XB4,
0X4E,0XB3,0X2A,0XC2,0X68,0XD1,0XE6,0XE0,0XA6,0XE8,0XA5,0XE8,0XA5,0XE8,0XE6,0XD8,
0X88,0XC9,0X06,0XA9,0X22,0XA8,0X02,0XA8,0X00,0XA0,0X00,0XC8,0X00,0XD8,0XF7,0XE5,
0XFF,0XE7,0XF8,0XAD,0XC4,0X10,0XE4,0X10,0X04,0X11,0XE4,0X10,0X05,0X11,0X8B,0X4A,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X55,0XA5,0X41,0X00,
0XA7,0X29,0X5D,0XDF,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XEF,0X7D,0XDF,0XDB,0XCE,0X59,0XCE,0XF8,0XCD,0XD7,0XCD,0XF7,0XC5,0X79,0XCE,
0XFB,0XBE,0XAB,0XA2,0X03,0XF0,0X45,0XF8,0X42,0XD0,0X43,0XE8,0X00,0XF0,0X72,0XD4,
0XFF,0XDF,0X39,0XAE,0XE4,0X10,0XE4,0X10,0X04,0X11,0XE4,0X10,0X05,0X11,0X87,0X29,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X59,0XCE,0X83,0X08,
0X46,0X21,0X1C,0XD7,0XFF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XEF,0X8B,0XBA,0X04,0XF8,0X45,0XF8,0X62,0XE0,0X44,0XF0,0X00,0XF8,0X8E,0XDB,
0XFF,0XDF,0XF8,0XA5,0XC4,0X10,0XE4,0X10,0XE4,0X10,0X04,0X11,0XE4,0X10,0X25,0X19,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XBE,0XF7,0X87,0X29,
0X83,0X08,0X39,0XB6,0XFF,0XF7,0XDF,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XBE,0XE7,0X4A,0XBA,0X03,0XF8,0X45,0XF8,0X64,0XF8,0X44,0XF8,0X00,0XF8,0X6E,0XE3,
0XFF,0XD7,0XF4,0X8C,0X83,0X08,0X04,0X11,0XE4,0X10,0XE4,0X10,0XE4,0X10,0X05,0X19,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XEF,0X73,
0X00,0X00,0X72,0X84,0XFF,0XEF,0XBE,0XEF,0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XDF,0XE7,0X8B,0XBA,0X03,0XF8,0X45,0XF8,0X45,0XF8,0X23,0XF8,0X00,0XF8,0XD3,0XD4,
0XFF,0XD7,0X4E,0X5B,0X21,0X00,0X29,0X3A,0X55,0XA5,0X83,0X08,0XC4,0X10,0X25,0X19,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFB,0XDE,
0XA3,0X08,0XE8,0X31,0X9E,0XDF,0X9E,0XE7,0XBF,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XF7,0X51,0XBC,0X02,0XE0,0X03,0XF8,0X03,0XF0,0X43,0XE0,0XEC,0XC2,0X7E,0XCF,
0XFC,0XBE,0X46,0X21,0X21,0X00,0XD3,0X94,0XFF,0XFF,0X51,0X84,0X00,0X00,0X87,0X29,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X51,0X84,0X00,0X00,0XF4,0X8C,0XFF,0XEF,0X9E,0XE7,0XBF,0XEF,0XDF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X3D,0XDF,0X55,0XBD,0X52,0XBC,0X72,0XBC,0XB7,0XB5,0X5D,0XC7,0XFF,0XDF,
0XF0,0X6B,0X00,0X00,0X09,0X3A,0XBF,0XF7,0XFF,0XFF,0XFF,0XFF,0X14,0X9D,0X55,0XA5,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XAC,0X4A,0XA4,0X08,0XBB,0XBE,0XDF,0XE7,0X7E,0XE7,0XBE,0XEF,0XDF,0XF7,
0XDF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XDF,0XFF,0XDF,0XF7,0XFF,0XEF,0XDF,0XDF,0XBF,0XD7,0X9E,0XD7,0XDF,0XDF,0XD8,0XA5,
0X83,0X08,0X26,0X11,0XDB,0XD6,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X79,0XEE,0X8B,0XDC,0X21,0X31,0XA9,0X21,0X3D,0XCF,0XBF,0XDF,0X7E,0XDF,0X9E,0XE7,
0XBE,0XEF,0XBF,0XEF,0XDF,0XF7,0XDF,0XF7,0XDF,0XF7,0XDF,0XF7,0XDF,0XF7,0XBF,0XEF,
0XBE,0XEF,0X9E,0XE7,0X7E,0XDF,0X5E,0XD7,0X5E,0XD7,0XDF,0XDF,0X9A,0XB6,0X26,0X19,
0X42,0X08,0XED,0XA3,0XBF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X74,0XDD,
0XC0,0XDB,0X00,0XFE,0X42,0XEE,0X02,0X42,0X89,0X21,0X7B,0XB6,0XDF,0XDF,0X7E,0XD7,
0X7E,0XDF,0X7E,0XDF,0X9E,0XE7,0X9E,0XE7,0X9E,0XE7,0X9E,0XE7,0X9E,0XE7,0X7E,0XDF,
0X7E,0XDF,0X5D,0XD7,0X5D,0XD7,0X9E,0XDF,0XFF,0XE7,0XF8,0XA5,0X07,0X11,0XE3,0X18,
0X02,0XC5,0X60,0XFD,0XE6,0XD3,0XDB,0XEE,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9E,0XF7,0X84,0XBA,
0XC1,0XFC,0X42,0XFE,0X82,0XFE,0XA2,0XFE,0X81,0X83,0X45,0X21,0X74,0X74,0X5E,0XC7,
0XDF,0XDF,0X7E,0XD7,0X5E,0XD7,0X5D,0XD7,0X5E,0XD7,0X5E,0XD7,0X5D,0XD7,0X5D,0XD7,
0X5E,0XD7,0X9E,0XDF,0XFF,0XE7,0X3D,0XC7,0XF1,0X63,0X84,0X08,0X42,0X52,0X26,0XE6,
0X29,0XFF,0X86,0XFE,0XE0,0XF3,0X6A,0XC3,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X18,0XDE,0XC1,0XD2,
0XA2,0XFD,0X22,0XFE,0X42,0XFE,0X42,0XFE,0X62,0XFE,0XE2,0XD4,0X41,0X6A,0X49,0X42,
0X53,0X74,0X3B,0XA6,0X3E,0XC7,0XBF,0XD7,0XBF,0XD7,0XBF,0XD7,0XBF,0XDF,0XBF,0XD7,
0X3E,0XC7,0X1A,0XA6,0XF2,0X63,0XA7,0X29,0X82,0X41,0X22,0XB4,0X62,0XFE,0X83,0XFE,
0XAA,0XFE,0X0F,0XFF,0X67,0XFD,0X63,0XBA,0X3C,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X9A,0XE6,0X80,0XD2,
0X21,0XFD,0XC2,0XFD,0XE2,0XF5,0XC2,0XF5,0X82,0XF5,0X82,0XFD,0X62,0XFD,0X61,0XDC,
0X21,0X9B,0X84,0X6A,0XE9,0X6A,0X2C,0X63,0XAF,0X63,0X11,0X74,0X6E,0X63,0X2C,0X63,
0X89,0X5A,0X04,0X52,0X81,0X7A,0XC2,0XCB,0XE2,0XFC,0X62,0XFD,0X82,0XFD,0XC2,0XFD,
0XC2,0XFD,0XE4,0XFD,0X24,0XFD,0X62,0XCA,0X1C,0XE7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XB1,0XCC,
0X81,0XD2,0XC0,0XF3,0XC1,0XFC,0X02,0XFD,0X02,0XFD,0XE2,0XFC,0XC2,0XFC,0XC2,0XFC,
0X81,0XFC,0X80,0XFB,0XC0,0XC9,0XA4,0X81,0X35,0XAD,0X59,0XCE,0X71,0X9C,0X21,0X81,
0X00,0XDA,0XA1,0XFB,0X82,0XFC,0XA2,0XFC,0X82,0XFC,0XA2,0XFC,0X02,0XFD,0X22,0XFD,
0XE2,0XFC,0X00,0XFC,0X60,0XDA,0X90,0XCC,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X5D,0XEF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X59,0XDE,0X0D,0XC4,0X06,0XCB,0XE4,0XD2,0X03,0XDB,0X03,0XDB,0XE3,0XDA,0XC3,0XD2,
0XA4,0XC2,0X09,0XB3,0XD2,0XBC,0X9E,0XF7,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFB,0XE6,
0X0E,0XB4,0XA6,0XBA,0X83,0XD2,0XE3,0XE2,0X02,0XEB,0X22,0XEB,0X22,0XE3,0X03,0XDB,
0XE4,0XD2,0X6A,0XC3,0XB6,0XD5,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
};
const unsigned char Font6x8[] =
{
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,   // sp
	 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00 ,   // !
	 0x00, 0x00, 0x07, 0x00, 0x07, 0x00 ,   // "
	 0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14 ,   // #
	 0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12 ,   // $
	 0x00, 0x62, 0x64, 0x08, 0x13, 0x23 ,   // %
	 0x00, 0x36, 0x49, 0x55, 0x22, 0x50 ,   // &
	 0x00, 0x00, 0x05, 0x03, 0x00, 0x00 ,   // '
	 0x00, 0x00, 0x1c, 0x22, 0x41, 0x00 ,   // (
	 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00 ,   // )
	 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14 ,   // *
	 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08 ,   // +
	 0x00, 0x00, 0x00, 0xA0, 0x60, 0x00 ,   // ,
	 0x00, 0x08, 0x08, 0x08, 0x08, 0x08 ,   // -
	 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 ,   // .
	 0x00, 0x20, 0x10, 0x08, 0x04, 0x02 ,   // /
	 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E ,   // 0
	 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00 ,   // 1
	 0x00, 0x42, 0x61, 0x51, 0x49, 0x46 ,   // 2
	 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31 ,   // 3
	 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10 ,   // 4
	 0x00, 0x27, 0x45, 0x45, 0x45, 0x39 ,   // 5
	 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30 ,   // 6
	 0x00, 0x01, 0x71, 0x09, 0x05, 0x03 ,   // 7
	 0x00, 0x36, 0x49, 0x49, 0x49, 0x36 ,   // 8
	 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E ,   // 9
	 0x00, 0x00, 0x36, 0x36, 0x00, 0x00 ,   // :
	 0x00, 0x00, 0x56, 0x36, 0x00, 0x00 ,   // ;
	 0x00, 0x08, 0x14, 0x22, 0x41, 0x00 ,   // <
	 0x00, 0x14, 0x14, 0x14, 0x14, 0x14 ,   // =
	 0x00, 0x00, 0x41, 0x22, 0x14, 0x08 ,  // >
	 0x00, 0x02, 0x01, 0x51, 0x09, 0x06 ,   // ?
	 0x00, 0x32, 0x49, 0x59, 0x51, 0x3E ,   // @
	 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C ,   // A
	 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36 ,   // B
	 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22 ,   // C
	 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C ,   // D
	 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41 ,   // E
	 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01 ,   // F
	 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A ,   // G
	 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F ,   // H
	 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00 ,   // I
	 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01 ,   // J
	 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41 ,   // K
	 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40 ,   // L
	 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F ,   // M
	 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F ,   // N
	 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E ,   // O
	 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06 ,   // P
	 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E ,   // Q
	 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46 ,   // R
	 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 ,   // S
	 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 ,   // T
	 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F ,   // U
	 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F ,   // V
	 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F ,   // W
	 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 ,   // X
	 0x00, 0x07, 0x08, 0x70, 0x08, 0x07 ,   // Y
	 0x00, 0x61, 0x51, 0x49, 0x45, 0x43 ,   // Z
	 0x00, 0x00, 0x7F, 0x41, 0x41, 0x00 ,   // [ 91
	 0x00, 0x02, 0x04 ,0x08, 0x10, 0x20 ,    // \92
	 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00 ,   // ]
	 0x00, 0x04, 0x02, 0x01, 0x02, 0x04 ,   // ^
	 0x00, 0x40, 0x40, 0x40, 0x40, 0x40 ,   // _
	 0x00, 0x00, 0x01, 0x02, 0x04, 0x00 ,   // '
	 0x00, 0x20, 0x54, 0x54, 0x54, 0x78 ,   // a
	 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38 ,   // b
	 0x00, 0x38, 0x44, 0x44, 0x44, 0x20 ,   // c
	 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F ,   // d
	 0x00, 0x38, 0x54, 0x54, 0x54, 0x18 ,   // e
	 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02 ,   // f
	 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C ,   // g
	 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78 ,   // h
	 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00 ,   // i
	 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00 ,   // j
	 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00 ,   // k
	 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00 ,   // l
	 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78 ,   // m
	 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78 ,   // n
	 0x00, 0x38, 0x44, 0x44, 0x44, 0x38 ,   // o
	 0x00, 0xFC, 0x24, 0x24, 0x24, 0x18 ,   // p
	 0x00, 0x18, 0x24, 0x24, 0x18, 0xFC ,   // q
	 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08 ,   // r
	 0x00, 0x48, 0x54, 0x54, 0x54, 0x20 ,   // s
	 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20 ,   // t
	 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C ,   // u
	 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C ,   // v
	 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C ,   // w
	 0x00, 0x44, 0x28, 0x10, 0x28, 0x44 ,   // x
	 0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C ,   // y
	 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44 ,   // z
	 0x14, 0x14, 0x14, 0x14, 0x14, 0x14     // horiz lines
};
const unsigned char Font16x8[]={
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //" "
	0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00,0x10,0x10,0x00,0x00, //"!"
	0x00,0x00,0x6C,0x6C,0x24,0x24,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00, //"""
	0x00,0x24,0x24,0x24,0x24,0xFE,0x48,0x48,0x48,0x48,0xFC,0x90,0x90,0x90,0x90,0x00, //"#"
	0x00,0x10,0x3C,0x54,0x92,0x90,0x50,0x38,0x14,0x12,0x12,0x92,0x54,0x78,0x10,0x00, //"$"
	0x00,0x00,0x22,0x5C,0x94,0xA8,0x48,0x10,0x10,0x24,0x2A,0x52,0x54,0x88,0x00,0x00, //"%"
	0x00,0x00,0x30,0x48,0x48,0x50,0x20,0x6E,0x54,0x94,0x8C,0x88,0x8A,0x74,0x00,0x00, //"&"
	0x00,0x00,0x30,0x30,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //"'"
	0x00,0x04,0x08,0x10,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0x10,0x10,0x08,0x04,0x00, //"("
	0x00,0x80,0x40,0x20,0x20,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x20,0x40,0x80,0x00, //")"
	0x00,0x00,0x00,0x00,0x10,0x54,0x38,0x10,0x38,0x54,0x10,0x00,0x00,0x00,0x00,0x00, //"*"
	0x00,0x00,0x00,0x10,0x10,0x10,0x10,0xFE,0x10,0x10,0x10,0x10,0x00,0x00,0x00,0x00, //"+"
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x20,0x00, //","
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //"-"
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x00, //"."
	0x00,0x00,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x40,0x40,0x80,0x80,0x00,0x00, //"/"
	0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00, //"0"
	0x00,0x00,0x10,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00, //"1"
	0x00,0x00,0x38,0x44,0x82,0x82,0x04,0x08,0x10,0x20,0x40,0x82,0x84,0xFC,0x00,0x00, //"2"
	0x00,0x00,0x38,0x44,0x82,0x02,0x04,0x38,0x04,0x02,0x02,0x82,0x44,0x38,0x00,0x00, //"3"
	0x00,0x00,0x04,0x0C,0x14,0x14,0x24,0x24,0x44,0x44,0xFE,0x04,0x04,0x0E,0x00,0x00, //"4"
	0x00,0x00,0xFC,0x80,0x80,0x80,0xB8,0xC4,0x82,0x02,0x02,0x82,0x84,0x78,0x00,0x00, //"5"
	0x00,0x00,0x3C,0x42,0x82,0x80,0xB8,0xC4,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00, //"6"
	0x00,0x00,0x7E,0x42,0x82,0x04,0x04,0x08,0x08,0x08,0x10,0x10,0x10,0x10,0x00,0x00, //"7"
	0x00,0x00,0x38,0x44,0x82,0x82,0x44,0x38,0x44,0x82,0x82,0x82,0x44,0x38,0x00,0x00, //"8"
	0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x46,0x3A,0x02,0x82,0x44,0x38,0x00,0x00, //"9"
	0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x00,0x00,0x00, //":"
	0x00,0x00,0x00,0x00,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x20,0x00,0x00, //";"
	0x00,0x00,0x00,0x00,0x06,0x18,0x60,0x80,0x60,0x18,0x06,0x00,0x00,0x00,0x00,0x00, //"<"
	0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00,0x00,0xFE,0x00,0x00,0x00,0x00,0x00,0x00, //"="
	0x00,0x00,0x00,0x00,0xC0,0x30,0x0C,0x02,0x0C,0x30,0xC0,0x00,0x00,0x00,0x00,0x00, //">"
	0x00,0x38,0x44,0x82,0x82,0x02,0x04,0x08,0x10,0x10,0x10,0x00,0x10,0x10,0x00,0x00, //"?"
	0x00,0x00,0x38,0x44,0x82,0x9A,0xAA,0xAA,0xAA,0xAA,0xAA,0x96,0x80,0x42,0x3C,0x00, //"@"
	0x00,0x00,0x10,0x10,0x10,0x28,0x28,0x28,0x44,0x44,0x7C,0x44,0x44,0xEE,0x00,0x00, //"A"	
	0x00,0x00,0xFC,0x42,0x42,0x42,0x42,0x7C,0x42,0x42,0x42,0x42,0x42,0xFC,0x00,0x00, //"B"
	0x00,0x00,0x3C,0x44,0x82,0x80,0x80,0x80,0x80,0x80,0x82,0x82,0x44,0x38,0x00,0x00, //"C"
	0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x44,0xF8,0x00,0x00, //"D"
	0x00,0x00,0xFC,0x44,0x42,0x40,0x44,0x7C,0x44,0x40,0x40,0x42,0x44,0xFC,0x00,0x00, //"E"
	0x00,0x00,0xFC,0x44,0x42,0x40,0x44,0x7C,0x44,0x40,0x40,0x40,0x40,0xF0,0x00,0x00, //"F"
	0x00,0x00,0x34,0x4C,0x82,0x80,0x80,0x80,0x8E,0x84,0x84,0x84,0x4C,0x34,0x00,0x00, //"G"
	0x00,0x00,0xEE,0x44,0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44,0x44,0xEE,0x00,0x00, //"H"
	0x00,0x00,0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x7C,0x00,0x00, //"I"
	0x00,0x00,0x3E,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x88,0x88,0x70,0x00,0x00, //"J"
	0x00,0x00,0xEE,0x44,0x48,0x48,0x50,0x60,0x50,0x48,0x48,0x44,0x44,0xEE,0x00,0x00, //"K"
	0x00,0x00,0xE0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x42,0x44,0xFC,0x00,0x00, //"L"
	0x00,0x00,0xC6,0x44,0x6C,0x6C,0x6C,0x54,0x54,0x54,0x44,0x44,0x44,0xEE,0x00,0x00, //"M"
	0x00,0x00,0xCE,0x44,0x64,0x64,0x64,0x54,0x54,0x4C,0x4C,0x4C,0x44,0xE4,0x00,0x00, //"N"
	0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00, //"O"
	0x00,0x00,0xF8,0x44,0x42,0x42,0x42,0x44,0x78,0x40,0x40,0x40,0x40,0xE0,0x00,0x00, //"P"
	0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xBA,0x44,0x3C,0x02,0x00, //"Q"
	0x00,0x00,0xF0,0x48,0x44,0x44,0x44,0x48,0x70,0x48,0x44,0x44,0x44,0xE6,0x00,0x00, //"R"
	0x00,0x00,0x3C,0x44,0x82,0x80,0x40,0x30,0x0C,0x02,0x02,0x82,0x44,0x78,0x00,0x00, //"S"
	0x00,0x00,0x7C,0x54,0x92,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00, //"T"
	0x00,0x00,0xEE,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,0x00, //"U"
	0x00,0x00,0xEE,0x44,0x44,0x44,0x44,0x28,0x28,0x28,0x28,0x10,0x10,0x10,0x00,0x00, //"V"
	0x00,0x00,0xEE,0x44,0x54,0x54,0x54,0x54,0x54,0x54,0x28,0x28,0x28,0x28,0x00,0x00, //"W"
	0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0x28,0x28,0x44,0x44,0xEE,0x00,0x00, //"X"
	0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x28,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00, //"Y"
	0x00,0x00,0x7E,0x44,0x84,0x08,0x08,0x10,0x20,0x20,0x40,0x82,0x84,0xFC,0x00,0x00, //"Z"
	0x00,0x1C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x1C,0x00, //"["
	0x00,0x00,0xEE,0x44,0x54,0x54,0xFE,0x54,0x54,0x54,0x28,0x28,0x28,0x28,0x00,0x00, //"\"
	0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x70,0x00, //"]"
	0x00,0x30,0x48,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //"^"
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x00, //"_"
	0x00,0x40,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //"`"
	0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x84,0x04,0x7C,0x84,0x84,0x8C,0x76,0x00,0x00, //"a"
	0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x42,0x42,0x42,0x42,0x64,0x58,0x00,0x00, //"b"
	0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x80,0x80,0x80,0x80,0x44,0x38,0x00,0x00, //"c"
	0x00,0x00,0x0C,0x04,0x04,0x04,0x34,0x4C,0x84,0x84,0x84,0x84,0x4C,0x36,0x00,0x00, //"d"
	0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x84,0x84,0xFC,0x80,0x80,0x84,0x78,0x00,0x00, //"e"
	0x00,0x00,0x18,0x24,0x20,0x20,0xF8,0x20,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00, //"f"
	0x00,0x00,0x00,0x00,0x00,0x00,0x3A,0x44,0x44,0x78,0x80,0x7C,0x82,0x82,0x7C,0x00, //"g"
	0x00,0x00,0xC0,0x40,0x40,0x40,0x58,0x64,0x44,0x44,0x44,0x44,0x44,0xEE,0x00,0x00, //"h"
	0x00,0x00,0x10,0x10,0x00,0x00,0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00, //"i"
	0x00,0x00,0x10,0x10,0x00,0x00,0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x90,0x60,0x00, //"j"
	0x00,0x00,0xC0,0x40,0x40,0x40,0x5C,0x48,0x50,0x60,0x50,0x48,0x44,0xEE,0x00,0x00, //"k"
	0x00,0x00,0x30,0x10,0x10,0x10,0x10,0x11,0x10,0x10,0x10,0x10,0x10,0x39,0x00,0x00, //"l"
	0x00,0x00,0x00,0x00,0x00,0x00,0xAC,0xD2,0x92,0x92,0x92,0x92,0x92,0xD6,0x00,0x00, //"m"
	0x00,0x00,0x00,0x00,0x00,0x00,0x58,0xE4,0x44,0x44,0x44,0x44,0x44,0xEE,0x00,0x00, //"n"
	0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x44,0x82,0x82,0x82,0x82,0x44,0x38,0x00,0x00, //"o"
	0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0x64,0x42,0x42,0x42,0x64,0x58,0x40,0xE0,0x00, //"p"
	0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x4C,0x84,0x84,0x84,0x4C,0x34,0x04,0x0E,0x00, //"q"
	0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0x30,0x20,0x20,0x20,0x20,0x20,0x70,0x00,0x00, //"r"
	0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x88,0x84,0x60,0x18,0x84,0x44,0x78,0x00,0x00, //"s"
	0x00,0x00,0x00,0x20,0x20,0x20,0xF8,0x20,0x20,0x20,0x20,0x20,0x24,0x18,0x00,0x00, //"t"
	0x00,0x00,0x00,0x00,0x00,0x00,0xC6,0x42,0x42,0x42,0x42,0x42,0x46,0x3A,0x00,0x00, //"u"
	0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x28,0x10,0x10,0x00,0x00, //"v"
	0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x44,0x44,0x54,0x54,0x28,0x28,0x28,0x00,0x00, //"w"
	0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x44,0x28,0x10,0x10,0x28,0x44,0xEE,0x00,0x00, //"x"
	0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x44,0x44,0x28,0x28,0x10,0x10,0xA0,0xC0,0x00, //"y"
	0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x44,0x88,0x10,0x20,0x42,0x84,0xFC,0x00,0x00, //"z"
	0x00,0x0C,0x10,0x10,0x10,0x10,0x10,0x60,0x10,0x10,0x10,0x10,0x10,0x10,0x0C,0x00, //"{"
	0x00,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00, //"|"
	0x00,0xC0,0x20,0x20,0x20,0x20,0x20,0x18,0x20,0x20,0x20,0x20,0x20,0x20,0xC0,0x00, //"}"
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x72,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00, //"~"
};

void LCD_GPIO_Init(void)   //initial I/O configuation of lcd
{

	GPIO_InitTypeDef  GPIO_InitStructure;
	      
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB ,ENABLE);	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10| GPIO_Pin_11| GPIO_Pin_12| GPIO_Pin_13| GPIO_Pin_1| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}
void  SPI_WriteData(unsigned char Data)  // write a 8 bits date through spi bus
{
	unsigned char i=0;
	for(i=8;i>0;i--)
	{
		if(Data&0x80)	
			LCD_SDA_SET; 
    else LCD_SDA_CLR;
	   
    LCD_SCL_CLR;       
    LCD_SCL_SET;
    Data<<=1; 
	}
}

void Lcd_WriteIndex(unsigned char Index)// write a 8 bits command through spi bus
{ 
   LCD_CS_CLR;       //the begin of writing commands
   LCD_RS_CLR;
	 SPI_WriteData(Index);
   LCD_CS_SET;
}

void Lcd_WriteData(unsigned char Data)
{
   LCD_CS_CLR;
   LCD_RS_SET;
   SPI_WriteData(Data);
   LCD_CS_SET; 
}
void LCD_WriteData_16Bit(unsigned short Data)
{
   LCD_CS_CLR;
   LCD_RS_SET;
	 SPI_WriteData(Data>>8); 	
	 SPI_WriteData(Data); 			
 	 LCD_CS_SET; 
}

void Lcd_WriteReg(unsigned char Index,unsigned char Data)
{
	Lcd_WriteIndex(Index);
  Lcd_WriteData(Data);
}

void Lcd_Reset(void)
{
	LCD_RST_CLR;
	delayms(100);
	LCD_RST_SET;
	delayms(50);
}

void Lcd_Init(void) //LCD Init For 1.44Inch LCD Panel with ST7735R.
{	
	LCD_GPIO_Init();
	Lcd_Reset(); //Reset before LCD Init.

	//LCD Init For 1.44Inch LCD Panel with ST7735R.
	Lcd_WriteIndex(0x11);//Sleep exit 
	delayms (120);
		
	//ST7735R Frame Rate
	Lcd_WriteIndex(0xB1); 
	Lcd_WriteData(0x01); 
	Lcd_WriteData(0x2C); 
	Lcd_WriteData(0x2D); 

	Lcd_WriteIndex(0xB2); 
	Lcd_WriteData(0x01); 
	Lcd_WriteData(0x2C); 
	Lcd_WriteData(0x2D); 

	Lcd_WriteIndex(0xB3); 
	Lcd_WriteData(0x01); 
	Lcd_WriteData(0x2C); 
	Lcd_WriteData(0x2D); 
	Lcd_WriteData(0x01); 
	Lcd_WriteData(0x2C); 
	Lcd_WriteData(0x2D); 
	
	Lcd_WriteIndex(0xB4); //Column inversion 
	Lcd_WriteData(0x07); 
	
	//ST7735R Power Sequence
	Lcd_WriteIndex(0xC0); 
	Lcd_WriteData(0xA2); 
	Lcd_WriteData(0x02); 
	Lcd_WriteData(0x84); 
	Lcd_WriteIndex(0xC1); 
	Lcd_WriteData(0xC5); 

	Lcd_WriteIndex(0xC2); 
	Lcd_WriteData(0x0A); 
	Lcd_WriteData(0x00); 

	Lcd_WriteIndex(0xC3); 
	Lcd_WriteData(0x8A); 
	Lcd_WriteData(0x2A); 
	Lcd_WriteIndex(0xC4); 
	Lcd_WriteData(0x8A); 
	Lcd_WriteData(0xEE); 
	
	Lcd_WriteIndex(0xC5); //VCOM 
	Lcd_WriteData(0x0E); 
	
	Lcd_WriteIndex(0x36); //MX, MY, RGB mode 
	Lcd_WriteData(0xC8); 
	
	//ST7735R Gamma Sequence
	Lcd_WriteIndex(0xe0); 
	Lcd_WriteData(0x0f); 
	Lcd_WriteData(0x1a); 
	Lcd_WriteData(0x0f); 
	Lcd_WriteData(0x18); 
	Lcd_WriteData(0x2f); 
	Lcd_WriteData(0x28); 
	Lcd_WriteData(0x20); 
	Lcd_WriteData(0x22); 
	Lcd_WriteData(0x1f); 
	Lcd_WriteData(0x1b); 
	Lcd_WriteData(0x23); 
	Lcd_WriteData(0x37); 
	Lcd_WriteData(0x00); 	
	Lcd_WriteData(0x07); 
	Lcd_WriteData(0x02); 
	Lcd_WriteData(0x10); 

	Lcd_WriteIndex(0xe1); 
	Lcd_WriteData(0x0f); 
	Lcd_WriteData(0x1b); 
	Lcd_WriteData(0x0f); 
	Lcd_WriteData(0x17); 
	Lcd_WriteData(0x33); 
	Lcd_WriteData(0x2c); 
	Lcd_WriteData(0x29); 
	Lcd_WriteData(0x2e); 
	Lcd_WriteData(0x30); 
	Lcd_WriteData(0x30); 
	Lcd_WriteData(0x39); 
	Lcd_WriteData(0x3f); 
	Lcd_WriteData(0x00); 
	Lcd_WriteData(0x07); 
	Lcd_WriteData(0x03); 
	Lcd_WriteData(0x10);  
	
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x7f);

	Lcd_WriteIndex(0x2b);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x00);
	Lcd_WriteData(0x9f);
	
	Lcd_WriteIndex(0xF0); //Enable test command  
	Lcd_WriteData(0x01); 
	Lcd_WriteIndex(0xF6); //Disable ram power save mode 
	Lcd_WriteData(0x00); 
	
	Lcd_WriteIndex(0x3A); //65k mode 
	Lcd_WriteData(0x05); 
	
	
	Lcd_WriteIndex(0x29);//Display on	
	LCD_LED_SET;
}

void Lcd_SetRegion(unsigned short x_start,unsigned short y_start,unsigned short x_end,unsigned short y_end)
{		
	Lcd_WriteIndex(0x2a);
	Lcd_WriteData(0x00);
	Lcd_WriteData(x_start+2);
	Lcd_WriteData(0x00);
	Lcd_WriteData(x_end+2);

	Lcd_WriteIndex(0x2b);
	Lcd_WriteData(0x00);
	Lcd_WriteData(y_start+1);
	Lcd_WriteData(0x00);
	Lcd_WriteData(y_end+1);
	
	Lcd_WriteIndex(0x2c);
}

void Lcd_SetXY(unsigned short x,unsigned short y)
{
  	Lcd_SetRegion(x,y,x,y);
}
	
void Gui_DrawPoint(unsigned short x,unsigned short y,unsigned short Data)
{
	Lcd_SetRegion(x,y,x+1,y+1);
	LCD_WriteData_16Bit(Data);

}    

unsigned int Lcd_ReadPoint(unsigned short x,unsigned short y)
{
  unsigned int Data;
  Lcd_SetXY(x,y);
  Lcd_WriteData(Data);
  return Data;
}

void Lcd_Clear(unsigned short Color)               
{	
   unsigned int i,m;
   Lcd_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
   Lcd_WriteIndex(0x2C);
   for(i=0;i<X_MAX_PIXEL;i++)
    for(m=0;m<Y_MAX_PIXEL;m++)
    {	
	  	LCD_WriteData_16Bit(Color);
    }   
}

unsigned int LCD_BGR2RGB(unsigned int c)  
{
  unsigned short  r,g,b,rgb;   
  b=(c>>0)&0x1f;
  g=(c>>5)&0x3f;
  r=(c>>11)&0x1f;	 
  rgb=(b<<11)+(g<<5)+(r<<0);		 
  return(rgb);
}

void LCD_P6x8Char(unsigned short x, unsigned short y, unsigned short fc, unsigned short bc, unsigned char s)
{
		unsigned char i,j,k;
		if((s) < 128) 
		{
			k=s;
			if (k>32) k-=32; else k=0;
	
			for(i=0;i<8;i++)
				for(j=0;j<6;j++) 
				{
				    if(Font6x8[k*6+j]&(0x01<<i))	
							  Gui_DrawPoint(x+j,y+i,fc);
						else 
						{
							if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
						}
				}
		}

}
void LCD_P6x8Str(unsigned short x, unsigned short y, unsigned short fc, unsigned short bc, unsigned char *s)
{
	unsigned char i,j,k;
	while(*s) 
	{	
		if((*s) < 128) 
		{
			k=*s;
			if (k>32) k-=32; else k=0;
	
			for(i=0;i<8;i++)
				for(j=0;j<6;j++) 
				{
				    if(Font6x8[k*6+j]&(0x01<<i))	
							  Gui_DrawPoint(x+j,y+i,fc);
						else 
						{
							if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
						}
				}
			x+=6;
		}
		s++;		
	}
}
void LCD_P8x16Char(unsigned short x, unsigned short y, unsigned short fc, unsigned short bc, unsigned char s)
{
	unsigned char i,j,k;

	if(s < 128) 
	{
		k = s;
		if (k>32) k-=32; else k=0;

		for(i=0;i<16;i++)
			for(j=0;j<8;j++) 
			{
		    if(Font16x8[k*16+i]&(0x80>>j))	
					Gui_DrawPoint(x+j,y+i,fc);
				else 
				{
					if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
				}
			}
	}
}
void LCD_P8x16Str(unsigned short x, unsigned short y, unsigned short fc, unsigned short bc, unsigned char *s)
{
	unsigned char i,j,k;
	while(*s) 
	{	
		if((*s) < 128) 
		{
			k=*s;
			if (k>32) k-=32; else k=0;
	
			for(i=0;i<16;i++)
				for(j=0;j<8;j++) 
				{
				    if(Font16x8[k*16+i]&(0x80>>j))	
							  Gui_DrawPoint(x+j,y+i,fc);
						else 
						{
							if (fc!=bc) Gui_DrawPoint(x+j,y+i,bc);
						}
				}
			x+=8;
		}
		s++;		
	}
}

void LCD_P6x8Value(unsigned short x, unsigned short y, unsigned short fc, unsigned short bc,int data)
{
	unsigned short val[5],k; 
	if(data < 0)
	{
		LCD_P6x8Char(x,y,fc,bc,'-');
		data = - data;	
	}
	else
	{
		LCD_P6x8Char(x,y,fc,bc,' ');
	}
	if(data>100000)
	{
		LCD_P6x8Str(x,y,fc,bc,"Over!!");
	}
	else if(data >1000)
	{
		val[0] = (data%100000)/10000;
		val[1] = (data%10000)/1000;
		val[2] = (data%1000)/100;
		val[3] = (data%100)/10;
		val[4] = data%10;
		if(val[0]!=0) 	LCD_P6x8Char(x+6,y,fc,bc,val[0]+48);
		if(val[1]!=0||(val[1]==0&&val[1]!=0)) LCD_P6x8Char(x+12,y,fc,bc,val[1]+48);
		
			for(k=2;k<5;k++)
			{
				LCD_P6x8Char(x+6*(k+1),y,fc,bc,val[k]+48); 
			}
	}
	else
	{
		val[0] = (data%1000)/100;
		val[1] = (data%100)/10;
		val[2] = data%10;
		if(val[0]!=0) LCD_P6x8Char(x+6,y,fc,bc,val[0]+48);
		if(val[1]!=0||(val[1]==0&&val[1]!=0))LCD_P6x8Char(x+12,y,fc,bc,val[1]+48);
		LCD_P6x8Char(x+18,y,fc,bc,val[2]+48);
		
	}		
}

void LCD_P8x16Value(unsigned short x, unsigned short y, unsigned short fc, unsigned short bc,int data)
{
	unsigned short val[5],k; 
	if(data < 0)
	{
		LCD_P8x16Char(x,y,fc,bc,'-');
		data = - data;	
	}
	else
	{
		LCD_P8x16Char(x,y,fc,bc,' ');
	}
	if(data>100000)
	{
		LCD_P8x16Str(x,y,fc,bc,"Over!!");
	}
	else if(data >1000)
	{
		val[0] = (data%100000)/10000;
		val[1] = (data%10000)/1000;
		val[2] = (data%1000)/100;
		val[3] = (data%100)/10;
		val[4] = data%10;
		if(val[0]!=0) 	LCD_P8x16Char(x+8,y,fc,bc,val[0]+48);
		if(val[1]!=0||(val[1]==0&&val[1]!=0)) LCD_P8x16Char(x+16,y,fc,bc,val[1]+48);
		
			for(k=2;k<5;k++)
			{
				LCD_P8x16Char(x+8*(k+1),y,fc,bc,val[k]+48); 
			}
	}
	else
	{
		val[0] = (data%1000)/100;
		val[1] = (data%100)/10;
		val[2] = data%10;
		if(val[0]!=0) LCD_P8x16Char(x+8,y,fc,bc,val[0]+48);
		if(val[1]!=0||(val[1]==0&&val[1]!=0))LCD_P8x16Char(x+16,y,fc,bc,val[1]+48);
		LCD_P8x16Char(x+24,y,fc,bc,val[2]+48);
		
	}		
}


void LCD_PutImage(unsigned short x, unsigned short y) //显示120*120 QQ图片
{ 
	unsigned char i,picH,picL;
	Lcd_SetRegion(x,y,x+39,y+39);		//坐标设置
	for(i=0;i<40*40;i++)
	{	
		picL=Image[i*2];	//数据低位在前
		picH=Image[i*2+1];				
		LCD_WriteData_16Bit(picH<<8|picL);  						
	}					
}
