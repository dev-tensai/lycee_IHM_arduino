#include "Servo.h"

Servo FS90;
Servo FS90R;

byte FS90_pin = 9;
byte FS90R_pin = 10;
byte incoming;

void setup() {
  FS90.attach(FS90_pin, 500, 2500);
  FS90R.attach(FS90R_pin, 700, 2300);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0) {
    incoming = Serial.read();
    Serial.println("Code ascii envoyé :");
    Serial.println(incoming);
    Serial.println();
    switch(incoming) {
      case 118:
      FS90.write(0);
      write360(1, 100);
      Serial.println("FS90 : Angle mini");
      Serial.println("FS90R : Vitesse maxi horaire");
      Serial.println();
      break;

      case 98:
      FS90.write(90);
      write360(0, 0);
      Serial.println("FS90 : Angle moyen");
      Serial.println("FS90R : Arrêt");
      Serial.println();
      break;
    
      case 110:
      FS90.write(180);
      write360(0, 100);
      Serial.println("FS90 : Angle maxi");
      Serial.println("FS90R : Vitesse maxi anti-horaire");
      Serial.println();
      break;
      
      default:
      Serial.println("Erreur de code");
      break;
    }
  }
}

int write360(bool x, byte y) {
  if(x) {
    float speed1 = 90+(y*0.9);
    FS90R.write(speed1);
  } else {
    float speed0 = 90-(y*0.9);
    FS90R.write(speed0);
  }
}