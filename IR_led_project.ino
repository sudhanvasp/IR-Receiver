/*
 *
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
int enA = 10;       //the pwm pin
int in1 = 9;        //the terminal 1 of the motor
int in2 = 8;        //the terminal 2 of the motor
int RECV_PIN = 11;  // the receiving pin for the IR Reciever
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{ pinMode(enA, OUTPUT);   //defining all the pin
  pinMode(in1, OUTPUT);   
  pinMode(in2, OUTPUT);
  
                          //test run
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  delay(3000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
                           //test done
                          
  Serial.begin(9600);      //Starting Serial Monitor
  irrecv.enableIRIn();     //Start the IR receiver
  
  Serial.println("Hello There");
  Serial.print("Ready for commands");
  
}

void loop()
{ digitalWrite(in1, HIGH); //We start the motor
  digitalWrite(in2, LOW);  //One pin as positive and other as negative
  if (irrecv.decode(&results))   //looks for a button press from the IR remote
    {
     Serial.println(results.value, HEX);
     if (results.value == "FF6897"){ //FF6897 is 0 on remote
     analogWrite(enA, 0);
     Serial.println("Button 0 pressed. Speed set to 0");
     }
     if (results.value == "FF30CF" ){ //FF30CF  is 1 on remote
     analogWrite(enA, 28); 
     Serial.println("Button 1 pressed. Speed set to 11%");
     }
     
     if (results.value == "FF18E7" ){ //FF18E7  is 2 on remote
     analogWrite(enA, 56); 
     Serial.println("Button 2 pressed. Speed set to 22");
     }
    
     if (results.value == "FF7A85"  ){ //FF7A85  is 3 on remote
     analogWrite(enA, 84); 
     Serial.println("Button 3 pressed. Speed set to 33");
     }
     if (results.value == "FF10EF" ){ //FF10EF  is 4 on remote
     analogWrite(enA, 112); 
     Serial.println("Button 4 pressed. Speed set to 44");
     }
     if (results.value == "FF38C7" ){ //FF38C7  is 5 on remote
     analogWrite(enA, 140); 
     Serial.println("Button 5 pressed. Speed set to 55");
     }
     if (results.value == "FF5AA5" ){ //FF5AA5  is 6 on remote
     analogWrite(enA, 168); 
     Serial.println("Button 6 pressed. Speed set to 66");
     }
     if (results.value == "FF42BD" ){ //FF42BD  is 7 on remote
     analogWrite(enA, 196); 
     Serial.println("Button 7 pressed. Speed set to 77");
     }
     if (results.value == "FF48B5" ){ //FF48B5  is 8 on remote
     analogWrite(enA, 220); 
     Serial.println("Button 8 pressed. Speed set to 88%");
     }
     if (results.value == "FF52AD" ){ //FF52AD  is 9 on remote
     analogWrite(enA, 255); 
     Serial.println("Button 9 pressed. Speed set to 100%");
     }
     irrecv.resume(); // Receive the next value
    }
}
