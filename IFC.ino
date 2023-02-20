#include <PS4Controller.h>

//Motor A
int dir1PinA = 15;
int dir2PinA = 16;
int speedPinA = 17;

//Motor B
int dir1PinB = 22;
int dir2PinB = 21;
int speedPinB = 19;


double Speed = 1;


void setup() {
  Serial.begin(115200);
  // old PS4.begin("78:e3:6d:0a:c2:6e");
  PS4.begin("3c:71:bf:c8:02:c2");
  Serial.println("Ready.");

  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(speedPinA, OUTPUT);
  
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);
  pinMode(speedPinB, OUTPUT);
}

void loop() {
  if (PS4.isConnected()) {
    Serial.println("Connected!");
  }

  if (PS4.isConnected()) {
  
      if (PS4.Up()){
        forward(); 
        Serial.println("Up Button");
      }
        else
        {
        stop_motors(); 
        }
      

      
      
      if (PS4.Right()){
        turn_right();
        Serial.println("Right Button"); 
      }
        else
        {
        stop_motors(); 
        }

        
      
      if (PS4.Down()){
        backward();
        Serial.println("Down Button"); 
      }
        else
        {
        stop_motors(); 
        }

        
      
      if (PS4.Left()){
        turn_left();
        Serial.println("Left Button"); 
      }
        else
        {
        stop_motors(); 
        }


 

      if (PS4.R1()){
        Speed += 0,1;
        Serial.println("R1 Button");
        delay(500);
      } 



      if (PS4.L1()){
        Speed -= 0,1;
        Serial.println("L1 Button");
        delay(500);
      }
      
  }


}

//Fahrfunktionen

void backward() {
  // Motor A
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  digitalWrite(speedPinA, Speed);
  // Motor B
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  digitalWrite(speedPinB, Speed);
}


void forward() {
  // Motor A
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  digitalWrite(speedPinA, Speed);
  // Motor B
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  digitalWrite(speedPinB, Speed);
}


void turn_right() {
  // Motor A
  digitalWrite(dir1PinA, HIGH);
  digitalWrite(dir2PinA, LOW);
  digitalWrite(speedPinA, Speed);
  // Motor B
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, HIGH);
  digitalWrite(speedPinB, Speed);
}

void turn_left() {
  // Motor A
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, HIGH);
  digitalWrite(speedPinA, Speed);
  // Motor B
  digitalWrite(dir1PinB, HIGH);
  digitalWrite(dir2PinB, LOW);
  digitalWrite(speedPinB, Speed);
}


void stop_motors() {
  // Motor A
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);
  digitalWrite(speedPinA, Speed);
  // Motor B
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);
  digitalWrite(speedPinB, Speed);
}
