/*Reverse engineered example code for FreaksCar from ElecFreaks
 * by Alex Nunn
 * January 8th, 2020
 * 
 * Missing pins for:
 * Ultrasonic sensor - 2
 * IR sensors - 5
 * Back bumper switch - 1
 * IR receiver for remote - 1
 * Bluetooth module - 3????
 * Optical encoder for motors - 2-4?
*/

const int UNKNOWN0 = 0;
const int UNKNOWN1 = 1;
const int UNKNOWN2 = 2;
const int UNKNOWN3 = 3;
const int UNKNOWN4 = 4;
const int RIGHTBACK = 5;
const int RIGHTFORWARD = 6;
const int UNKNOWN7 = 7;
const int UNKNOWN8 = 8;
const int LEFTBACK = 9;
const int LEFTFORWARD = 10;
const int BUZZER = 11;
const int UNKNOWN12 = 12;
const int LED = 13; 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(RIGHTFORWARD, OUTPUT);
  pinMode(RIGHTBACK, OUTPUT);
  pinMode(LEFTFORWARD, OUTPUT);
  pinMode(LEFTBACK, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  moveForward();
  delay(5000);
  stopMoving();
  delay(1000);
  moveBackward();
  delay(5000);
  stopMoving();
  delay(1000);
  testBuzzer();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}

void moveForward(){
  digitalWrite(RIGHTBACK, LOW);
  digitalWrite(LEFTBACK, LOW);
  delay(20);
  digitalWrite(RIGHTFORWARD, HIGH);
  digitalWrite(LEFTFORWARD, HIGH);
}
void stopMoving(){
  digitalWrite(RIGHTBACK, LOW);
  digitalWrite(LEFTBACK, LOW);
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(LEFTFORWARD, LOW);
}
void moveBackward(){
  digitalWrite(RIGHTFORWARD, LOW);
  digitalWrite(LEFTFORWARD, LOW);
  delay(20);
  digitalWrite(RIGHTBACK, HIGH);
  digitalWrite(LEFTBACK, HIGH);
}

void testBuzzer(){
  analogWrite(BUZZER, 100);
  delay(1000);
  analogWrite(BUZZER, 0);
}


//This powers up each pin for a half second to test what it does. 
//Blinks pin 13 to indicate the number pin it is testing.

void testAllPins(){  
  for(int i=0; i<13; i++){
    pinMode(i, OUTPUT);
  }
  delay(10);
  for(int i=0; i<13; i++){
    for(int j=0; j<=i; j++){
      digitalWrite(LED, LOW);
      delay(50);
      digitalWrite(LED, HIGH);
      delay(50);
    }
    
    digitalWrite(i, LOW);
    delay(5);
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
  }
