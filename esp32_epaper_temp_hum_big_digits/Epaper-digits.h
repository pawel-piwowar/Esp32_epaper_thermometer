#ifndef Epaper - digits.h
#define Epaper -digits.h

#include <Arduino.h>

extern const int digits_font_width;
extern const int digits_font_high;
extern const int digits_dot_width;
extern const int digits_celc_width;
extern const int digits_perc_width;

extern const unsigned char gImage_dot[];
extern const unsigned char gImage_celc[];
extern const unsigned char gImage_perc[];
extern const unsigned char gImage_temp[];
extern unsigned char gImage_digits[10][583];

class EpaperBigDigits {
private:
  void digits_init_inter(void);
public:
  void digits_init(void);
};


#endif
