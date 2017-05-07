 
#include <Wire.h>


// 7-segment display driver (SAA1064)
static const char i2caddr = 0x38;

/* Segment bits:
  0 - a
  1 - b
  2 - c
  3 - d
  4 - e
  5 - f
  6 - g
  7 - DP
*/

static const char DIGITS[16] = {
  /* #  g f e   d c b a    val */
  /* 0  0 1 1   1 1 1 1 */ 0x3f,
  /* 1  0 0 0   0 1 1 0 */ 0x06,
  /* 2  1 0 1   1 0 1 1 */ 0x5b,
  /* 3  1 0 0   1 1 1 1 */ 0x4f,
  /* 4  1 1 0   0 1 1 0 */ 0x66,
  /* 5  1 1 0   1 1 0 1 */ 0x6d,
  /* 6  1 1 1   1 1 0 1 */ 0x7d,
  /* 7  0 0 0   0 1 1 1 */ 0x07,
  /* 8  1 1 1   1 1 1 1 */ 0x7f,
  /* 9  1 1 0   1 1 1 1 */ 0x6f,
  /* A  1 1 1   0 1 1 1 */ 0x77,
  /* b  1 1 1   1 1 0 0 */ 0x7c,
  /* C  0 1 1   1 0 0 1 */ 0x39,
  /* d  1 0 1   1 1 1 0 */ 0x5e,
  /* E  1 1 1   1 0 0 1 */ 0x79,
  /* F  1 1 1   0 0 0 1 */ 0x71
};

void saa1064_setup() {
  Wire.beginTransmission( i2caddr );

  // register address
  Wire.write( 0 );
  // control byte
  Wire.write( 0x70 ); // max. current

  Wire.endTransmission();
}

/* Digit order   D1 D0  */
void saa1064_set_digit(const int idx, const int digit) {
  Wire.beginTransmission( i2caddr );

  // digit byte
  Wire.write( 1 + idx );
  Wire.write( DIGITS[digit] );

  Wire.endTransmission();
}

void saa1064_set_hex_number(const char number) {
  saa1064_set_digit(1, (number & 0xf0) >> 4);
  saa1064_set_digit(0, (number & 0x0f));
}

void saa1064_set_dec_number(const char number) {
  saa1064_set_digit(1, number / 10);
  saa1064_set_digit(0, number % 10);
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  const int buttonPin = 2;

  saa1064_setup();

  saa1064_set_hex_number(0xef);

}

void loop() {
  // put your main code here, to run repeatedly:

}
