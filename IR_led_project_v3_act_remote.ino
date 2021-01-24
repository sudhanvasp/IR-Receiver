/*

  Recorded values from the IR remote (silver)

  PWR           FF629D
  CH            FFE21D
  |<<           FF22DD
  >|            FFC23D
  >>|           FF02FD
  -             FFE01F
  Plus          FFA857
  EQ            FF906F
  0             FF6897
  100           FF9867
  200           FFB04F
  1             FF30CF
  2             FF18E7
  3             FF7A85
  4             FF10EF
  5             FF38C7
  6             FF5AA5
  7             FF42BD
  8             FF48B5
  9             FF52AD
*/


#include <IRremote.h>
int enA = 3;       //the pwm pin
int in1 = 10;        //the terminal 1 of the motor
int in2 = 11;        //the terminal 2 of the motor
int RECV_PIN = 2;  // the receiving pin for the IR Reciever
int dir;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{ Serial.begin(9600); 
  pinMode(enA, OUTPUT);   //defining all the pin
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.println("Hello There");
  Serial.println("Test Begin");
  //test run
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(3000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  //test done

        //Starting Serial Monitor
  irrecv.enableIRIn();     //Start the IR receiver

  Serial.println("Test finished");
  Serial.print("Ready for commands");
  dir = 1;
}

void loop()
{ //digitalWrite(in1, HIGH); //We start the motor
//  digitalWrite(in2, LOW);  //One pin as positive and other as negative
  if (irrecv.decode(&results))   //looks for a button press from the IR remote
  {
//    Serial.println(results.value, HEX);
//    Serial.println(results.value);
    String val;
    
    val = String(results.value, HEX);
    if (val != "ffffffff"){
      Serial.println(val);
     
    }
    if (val == "1fe40bf") { //FF22DD is |<<
      dir = 0;
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      
    }
    else if (val == "1fec03f") { //FF02FD
      dir = 1;
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      
    }
    else if ( val == "1fe48b7"){// off button
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
    else if (val == "1fee01f") { //FF6897 is 0 on remote
      if (dir == 0) {
        analogWrite(in1, 0);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 0);
        digitalWrite(in1, LOW);
      }
      Serial.println("Button 0 pressed. Speed set to 0");
    }
    else if (val == "1fe50af" ) { //FF30CF  is 1 on remote
      if (dir == 0) {
        
        
        analogWrite(in1, 28);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 100);
        
        analogWrite(in2, 28);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 28);
      Serial.println("Button 1 pressed. Speed set to 11%");
    }

    else if (val == "1fed827" ) { //FF18E7  is 2 on remote
      if (dir == 0 ) {
        analogWrite(in1, 56);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 56);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 56);
      
      Serial.println("Button 2 pressed. Speed set to 22");
    }

    else if (val == "1fef807" ) { //FF7A85  is 3 on remote
      if (dir == 0) {
        analogWrite(in1, 84);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 84);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 84);
      Serial.println("Button 3 pressed. Speed set to 33");
    }

    else if (val == "1fe30cf" ) { //FF10EF  is 4 on remote
      if (dir == 0) {
        analogWrite(in1, 112);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 112);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 112);
      Serial.println("Button 4 pressed. Speed set to 44");
    }
    else if (val == "1feb04f" ) { //FF38C7  is 5 on remote
      if (dir == 0) {
        analogWrite(in1, 140);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 140);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 140);
      Serial.println("Button 5 pressed. Speed set to 55");
    }
    else if (val == "1fe708f" ) { //FF5AA5  is 6 on remote
      if (dir == 0) {
        analogWrite(in1, 168);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 168);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 168);
      Serial.println("Button 6 pressed. Speed set to 66");
    }
    if (val == "1fe00ff" ) { //FF42BD  is 7 on remote
      if (dir == 0) {
        analogWrite(in1, 196);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 196);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 196);
      Serial.println("Button 7 pressed. Speed set to 77");
    }
    else if (val == "1fef00f" ) { //FF4AB5  is 8 on remote
      if (dir == 0) {
        analogWrite(in1, 220);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 220);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 220);
      Serial.println("Button 8 pressed. Speed set to 88%");
    }
    else if (val == "1fe9867" ) { //FF52AD r is 9 on remote
      if (dir == 0) {
        analogWrite(in1, 255);
        digitalWrite(in2, LOW);
      }
      else if (dir == 1) {
        analogWrite(in2, 225);
        digitalWrite(in1, LOW);
      }
      analogWrite(enA, 255);
      Serial.println("Button 9 pressed. Speed set to 100%");
    }
    irrecv.enableIRIn();
    irrecv.resume(); // Receive the next value
  }
}
