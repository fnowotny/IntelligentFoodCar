//Display Stuff
#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI();  // Invoke library

float gewicht_wert = 123.45;
float temperatur_wert = 56.45;

//Motor ans PS4 Stuff
#include <PS4Controller.h>

//Motor A
int dir1PinA = 33;
int dir2PinA = 16;
int speedPinA = 17;

//Motor B
int dir1PinB = 22;
int dir2PinB = 21;
int speedPinB = 19;


double Speed = 1;


void setup() {
  //Display Stuff
  tft.init();
  tft.setRotation(4);
  tft.fillScreen(TFT_BLACK); // Bildschirm schwart loeschen
  
  //Motor and PS4 Stuff
  Serial.begin(115200);
  //PS4.begin("78:e3:6d:0a:c2:6e"); 
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
  //Motor Ansteuerung
  if (PS4.isConnected()) {

      //Display
      tft.setCursor(0, 0, 2);
      tft.setTextColor(TFT_BLUE,TFT_BLACK);  tft.setTextSize(4);
      tft.print("IFC"); tft.println(); 
      tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(2);
      tft.print("Gewicht: "); tft.println(gewicht_wert);  
      tft.setTextColor(TFT_WHITE,TFT_BLACK);  tft.setTextSize(2);
      tft.print("Temperatur: ");  tft.println(temperatur_wert); 
  
      if (PS4.Up()){
        forward(); 
        Serial.println("Up Button");
        tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
        tft.print("Nach Vorne  ");   
      }
      else{stop_motors();}     
      
      if (PS4.Right()){
        turn_right();
        Serial.println("Right Button");
        tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
        tft.print("Nach Rechts "); 
      }
      else{stop_motors();}     
      
      if (PS4.Down()){
        backward();
        Serial.println("Down Button");
        tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
        tft.print("Nach Hinten "); 
      }
      else{stop_motors();}     
      
      if (PS4.Left()){
        turn_left();
        Serial.println("Left Button"); 
        tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
        tft.print("Nach Links  ");
      }
      else{stop_motors();}     



      // Schaltung
      if (PS4.R1()){
        Speed = Speed + 0.5;
        if (Speed > 1.5) { Speed = 1.5 ; }
        Serial.println("R1 Button");
      } 


      if (PS4.L1()){
        Speed = Speed - 0.5;
        if (Speed < 0.5) { Speed = 0.5 ; }
        Serial.println("L1 Button");
      }
      
  }

}

//Fahrfunktionen für Motor
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
