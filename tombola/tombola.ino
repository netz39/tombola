 
#include <Wire.h>

static const char addr = 0x38;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  const int buttonPin = 2;
  Wire.beginTransmission( addr );
  // instruction byte
  Wire.write( 0 );
  // control byte
  Wire.write( 0x70 );
  Wire.write( 3 );
  Wire.write(255);
  Wire.write(0);
  Wire.write(0);
//  Wire.write( 2 );
//  Wire.write(3);
//  Wire.write(4);
  Wire.endTransmission();

}

void setDisplay( int num ){

}

// adresse des anzeigetreibers 0x70
void loop() {
  // put your main code here, to run repeatedly:

}
