#include <algorithm>
#include <iostream>
#include "Epaper-digits.h"

using namespace std;

const int digits_font_width = 53;
const int digits_font_high = 88;
const int digits_dot_width = 10;
const int digits_celc_width = 20;
const int digits_perc_width = 20;

const unsigned char gImage_0[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,
0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_1[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_2[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X02,0X00,
0X00,0X01,0X00,0XFF,0XFF,0XFF,0X81,0XFF,0XFE,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,
0XFF,0X80,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_3[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X81,0XFF,0XFE,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_4[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X80,0X00,
0X00,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,
0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFF,
0XFF,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_5[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X03,0XFF,
0XFF,0XFF,0X00,0X80,0X00,0X00,0X81,0XFF,0XFE,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,
0X00,0X80,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_6[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,
0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0XFF,0XFF,0XFF,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_7[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X80,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,
0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_8[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,
0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_9[583] = { /* 0X41,0X01,0X35,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X03,0XFF,
0XFF,0XFF,0X00,0X80,0X00,0X00,0X81,0XFF,0XFE,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,
0X00,0X80,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0X80,0X00,0X00,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,
0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,
0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,
0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,
0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,
0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,
0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,
0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,
0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,
0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,
0X7F,0XFC,0X03,0XFF,0XFF,0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFC,0X03,0XFF,0XFF,
0XFF,0X00,0XFF,0XFF,0XFF,0X80,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,
0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,
0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,
0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0X7F,0XFC,0X02,0X00,0X00,0X01,0X00,0X80,
0X00,0X00,0X80,0X7F,0XFE,0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X80,0XFF,0XFF,
0X02,0X00,0X00,0X01,0X00,0X80,0X00,0X00,0X81,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_dot[110] = { /* 0X41,0X01,0X0A,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X0F,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X07,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X03,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFE,0X07,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};

const unsigned char gImage_celc[220] = { /* 0X41,0X01,0X14,0X00,0X58,0X00, */
0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XE0,0X3F,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XC0,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,
0XFF,0XFF,0X9F,0XCF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X8C,0X7F,0XFF,0X3F,0XE0,0X00,
0X03,0XFF,0XFF,0XFF,0XFF,0X9E,0X7F,0XFE,0X78,0X70,0X00,0X00,0XFF,0XFF,0XFF,0XFF,
0X9E,0X7F,0XFC,0X70,0X3F,0XFF,0XFC,0X7F,0XFF,0XFF,0XFF,0X8C,0X7F,0XFC,0XE0,0X1F,
0XFF,0XFE,0X3F,0XFF,0XFF,0XFF,0XC0,0XFF,0XFC,0XE0,0X00,0X01,0XFF,0X3F,0XFF,0XFF,
0XFF,0XE1,0XFF,0XFC,0XE0,0X00,0X01,0XFF,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFC,0XE0,
0X1F,0XFF,0XFE,0X3F,0XFF,0XFE,0X00,0X00,0XFF,0XFC,0X70,0X3F,0XFF,0XFC,0X7F,0XFF,
0XFC,0X00,0X00,0X7F,0XFE,0X78,0X70,0X00,0X00,0XFF,0XFF,0XFC,0X00,0X00,0X7F,0XFF,
0X3F,0XE0,0X00,0X03,0XFF,0XFF,0XFC,0X7F,0XFC,0X7F,0XFF,0X9F,0XCF,0XFF,0XFF,0XFF,
0XFF,0XFC,0X7F,0XFC,0X7F,0XFF,0XC0,0X1F,0XCF,0XF3,0XFF,0XFF,0XFC,0X7F,0XFC,0X7F,
0XFF,0XE0,0X3F,0XCE,0X73,0XFF,0XFF,0XFC,0X7F,0XFC,0X7F,0XFF,0XFF,0XFF,0XCE,0X73,
0XFF,0XFF,0XFC,0X7F,0XFC,0X7F,0XFF,0XFF,0XFF,0XCF,0XF3,0XFF,0XFF,0XFE,0X7F,0XFC,
0XFF,0XFF,0XFF,0XFF,0XCF,0XF3,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};


const unsigned char gImage_perc[220] = { /* 0X41,0X01,0X14,0X00,0X58,0X00, */
0XFF,0XFE,0X1F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XF0,0X03,0XFF,0XFF,
0XFF,0XFF,0XFF,0XFF,0XE1,0XFF,0XFF,0XE3,0XF0,0XFF,0XFF,0XFF,0XFF,0XFF,0X9F,0XC0,
0XFF,0XFF,0XCF,0XFC,0X7F,0XFF,0XFF,0XFF,0XFF,0X8F,0X8C,0X7F,0XFF,0X9F,0XFE,0X1F,
0XFF,0XFF,0XFF,0XFF,0XC7,0X9E,0X7F,0XFF,0X3F,0XFE,0X0F,0XFF,0XFF,0XFF,0XFF,0XE3,
0X9E,0X7F,0XFF,0X3F,0XFC,0X03,0XFF,0XFF,0XFF,0XFF,0XF1,0X8C,0X7F,0XFF,0X7F,0XF0,
0X00,0XFF,0XFF,0XFF,0XFF,0XF8,0XC0,0XFF,0XFE,0X7F,0XE0,0X00,0X7F,0XFF,0XFF,0XFF,
0XFC,0X61,0XFF,0XFE,0X7F,0XC0,0X00,0X1F,0XFF,0XFF,0XFF,0XFE,0X3F,0XFF,0XFE,0X7F,
0X80,0X00,0X3F,0XFF,0XFF,0XFF,0X87,0X1F,0XFF,0XFE,0X7F,0X00,0X00,0X7F,0XFF,0XFF,
0XFF,0X03,0X8F,0XFF,0XFF,0X7E,0X00,0X01,0XFF,0XFF,0XFF,0XFE,0X31,0XC7,0XFF,0XFF,
0X3C,0X00,0X03,0XFF,0XFF,0XFF,0XFE,0X79,0XE3,0XFF,0XFF,0X18,0X00,0X0F,0XFF,0XFF,
0XFF,0XFE,0X79,0XF1,0XFF,0XFF,0X90,0X00,0X1F,0XFF,0XFF,0XFF,0XFE,0X31,0XF8,0XFF,
0XFF,0XC0,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0X03,0XFC,0X7F,0XFF,0XE0,0X01,0XFF,0XFF,
0XFF,0XFF,0XFF,0X87,0XFE,0X7F,0XFF,0XF8,0X03,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,
0XFF,0XFF,0XFF,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,};


unsigned char gImage_digits[10][583];

void EpaperBigDigits::digits_init(void){

  int digit_num = 0;
  copy(begin(gImage_0), end(gImage_0) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_1), end(gImage_1) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_2), end(gImage_2) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_3), end(gImage_3) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_4), end(gImage_4) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_5), end(gImage_5) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_6), end(gImage_6) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_7), end(gImage_7) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_8), end(gImage_8) , begin(gImage_digits[digit_num++]));
  copy(begin(gImage_9), end(gImage_9) , begin(gImage_digits[digit_num++]));
}


