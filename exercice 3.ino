// Servo - Version: Latest 
#include <Servo.h>


Servo FS90;
Servo FS90R;

byte FS90_pin=9;
byte FS90R_pin=10;

void setup(){
  FS90.attach(FS90_pin,900,2100);
  FS90R.attach(FS90R_pin,700,2300);
  Serial.begin(9600)
}
void loop(){
  FS90.write(0);
  FS90R.write(0);
  Serial.print(FS90: Angle mini)
  Serial.print(FS90R: Vitesse  maxi horaire)
  Serial.println()
  delay(2000);

  FS90R.write(90);
  FS90.write(90);
  Serial.print(FS90: Angle moyen)
  Serial.print(FS90R: arrêt )
  Serial.println()
  delay(2000);

  FS90.write(180);
  FS90R.write(180);
  Serial.print(FS90: Angle maxi)
  Serial.print(FS90R:Vitesse  maxi antihoraire  )
  Serial.println()
  delay(2000);
  
}
