#include <Servo.h>
 
Servo servothumb;         
Servo servoindex;         
Servo servomiddle;
Servo servoring;
Servo servopinky;
 
char number[50];
char c;
int state = 0;
String myStringRec;
int stringCounter = 0;
bool stringCounterStart = false;
String myRevivedString;
int stringLength = 6;
 
int servoPinky,servoMiddle,servoIndex,servoThumb,servoRing;
int myVals[] ={0,0,0,0,0} ;
 
bool portable;
 
void setup() {
 
  Serial.begin(9600);
  servothumb.attach(9); 
  servoindex.attach(10); 
  servopinky.attach(11);
  servoring.attach(12);
  servomiddle.attach(13);
  delay(500);
   
}
 
void loop() {
 
   
receiveData();
if (servoPinky ==0){  servopinky.write(180);}else{servopinky.write(90);}
if (servoIndex ==0){  servoindex.write(180);}else{servoindex.write(90);}
if (servoMiddle ==0){  servomiddle.write(180);}else{servomiddle.write(90);}
if (servoThumb ==0){  servothumb.write(180);}else{servothumb.write(90);}
if (servoRing ==0){  servoring.write(180);}else{servoring.write(90);}

 
}

 
 
void receiveData() {
  int i = 0;
  while (Serial.available()) {
   char c = Serial.read();
   
    if (c == '$') {
      stringCounterStart = true;
    }
    if (stringCounterStart == true )
    {
      if (stringCounter < stringLength)
      {
        myRevivedString = String(myRevivedString + c);
        stringCounter++;
      }
      if (stringCounter >= stringLength) {
        stringCounter = 0; stringCounterStart = false;
        servoThumb = myRevivedString.substring(1, 2).toInt();
        servoIndex = myRevivedString.substring(2, 3).toInt();
        servoMiddle = myRevivedString.substring(3, 4).toInt();
        servoRing = myRevivedString.substring(4, 5).toInt();
        servoPinky = myRevivedString.substring(5, 6).toInt();
        
        
        
        
//        Serial.print(servoPinky);
//        Serial.print(" ");
//        Serial.print(servoRing);
//        Serial.print(" ");
//        Serial.print(servoMiddle);
//        Serial.print(" ");
//        Serial.print(servoIndex);
//        Serial.print(" ");
//        Serial.println(servoThumb);      
        myRevivedString = "";
      }
    }
  }
}
