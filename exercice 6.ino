#include "Servo.h"

Servo FS90;
Servo FS90R;

byte FS90_pin = 9;
byte FS90R_pin = 10;
byte incoming;
byte vitesse = 0;
bool marche_arret = 0;

void setup() {
  FS90.attach(FS90_pin, 500, 2500);
  FS90R.attach(FS90R_pin, 700, 2300);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0) {
    incoming = Serial.read();
    switch(incoming) {
      case 118:
      vitesse = ++vitesse;
      break;

      case 98:
      if(marche_arret) {
        marche_arret = 0;
      } else {
        marche_arret = 1;
      }
      break;
    
      case 110:
      vitesse = vitesse - 1;
      break;
      
      default:
      break;
    }
    if(marche_arret) {
      FS90.write(vitesse);
      write360(1, vitesse);
    } else {
      write360(0, vitesse);
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