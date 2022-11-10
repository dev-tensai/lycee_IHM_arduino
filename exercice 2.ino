#include <Servo.h>

Servo FS90;
Servo FS90R;

byte FS90_pin=9;
byte FS90R_pin=10;

void setup() {
  FS90.attach(FS90_pin,544,2400);
  FS90R.attach(FS90R_pin,544,2400);
}

void loop() {
   FS90.write(0);
   FS90R.write(0);
   delay(2000);

   FS90.write(90);
   FS90R.write(92);
   delay(2000);

   FS90.write(180);
   FS90R.write(180);
   delay(2000);

}
