#include "Servo.h"

//S0V012A012

Servo FS90;
Servo FS90R;

byte FS90_pin = 9;
byte FS90R_pin = 10;
String incoming;
byte vitesse = 0;
bool marche_arret = 0;
String testS;
String testV;
String testA;
String S;
String V;
String A;
int S_int;
int V_int;
int A_int;

void setup() {
  FS90.attach(FS90_pin, 500, 2500);
  FS90R.attach(FS90R_pin, 700, 2300);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0) {
    incoming = Serial.readStringUntil('\n');
    testS = incoming.substring(0, 1);
    testV = incoming.substring(2, 3);
    testA = incoming.substring(6, 7);
    if(testS == "S") {
      S = incoming.substring(1, 2);
    }
    if(testV == "V") {
      V = incoming.substring(3, 6);
      int V_int = V.toInt();
      if(V_int > 100) return;
      if(S == "1") {
        write360(1, V_int);
      } else {
        write360(0, V_int);
      }
    }
    if(testA == "A") {
      A = incoming.substring(7, 10);
      int A_int = A.toInt();
      if(A_int > 180) return;
      FS90.write(A_int);
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