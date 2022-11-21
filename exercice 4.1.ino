#include <Servo.h>

Servo FS90;
Servo FS90R;

byte FS90_pin=9;
byte FS90R_pin=10;
byte incomming;

void setup(){
  FS90.attach(FS90_pin,900,2100);
  FS90R.attach(FS90R_pin,700,2300);
  Serial.begin(9600);
  
}

void loop() {
  while (Serial.available() > 0) {
      incomming= Serial.read();
      Serial.print("code ascii envoye:");
      Serial.println(incomming);

       if (incomming == 118){ 
     FS90.write(0);
  FS90R.write(0);
  Serial.println("FS90: Angle mini");
  Serial.println("FS90R: Vitesse  maxi horaire");
  Serial.println();
  delay(2000);
  }
  else if(incomming == "98") {
 FS90R.write(90);
  FS90.write(90);
  Serial.println("FS90: Angle moyen");
  Serial.println("FS90R: arrêt\n");
  Serial.println();
  delay(2000);
  }
 else if(incomming == 110){
 FS90.write(180);
  FS90R.write(180);
  Serial.print("FS90: Angle maxi");
  Serial.print("FS90R:Vitesse  maxi antihoraire\n");
  Serial.println();
 }
  else {
      Serial.print("Erreur de Code\n");
      Serial.println();
  }
  }
  

 
}

