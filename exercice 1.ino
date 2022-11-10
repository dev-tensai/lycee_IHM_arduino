byte x = 40;
byte servopin = 9;

void setup(){
     pinMode(servopin,OUTPUT);
}
void loop(){
  for(byte n=0;n<x;n++){
  digitalWrite(servopin,HIGH);
  delay(1);
  digitalWrite(servopin,LOW);
  delay(19);
  }

  delay(2000);

   for(byte n=0;n<x;n++){
  digitalWrite(servopin,HIGH);
  digitalWrite(servopin,LOW);
   delayMicroseconds(1850);
   }
  delay(2000);

  for(byte n=0;n<x;n++){
  digitalWrite(servopin,HIGH);
  delay(2);
  digitalWrite(servopin,LOW);
  delay(18);
  }
  delay(2000);
}