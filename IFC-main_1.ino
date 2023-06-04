//
// IFC - Intelligent Food Car
// 
// L298N - Motor Dual Drive H-Bridge
//
//Zur Version: schöne Vorwärts/Rückwärtskurven, optimale Motoransteuerung, mit Display, mit Ulraschallsensoren
//

bool DEBUG=true;

//Display Stuff
#include <TFT_eSPI.h> // Graphics and font library for ILI9341 driver chip
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI();  // Invoke library


// PS4 Stuff
#include <PS4Controller.h>

// PWM Signal Stuff
#include <analogWrite.h>
int pwmwert = 200;          

unsigned long  hindernis1=100;
unsigned long  hindernis2=100;


//* Meine eigenen Libraries *//
#include "IFC_ESP_PIN_Definitionen.h"
#include "Motorsteuerung.h"
#include "Display.h"
#include "Ultraschallsensor.h"


// Setup Procedure
//
void setup() {
  // Serielle Konsole
  Serial.begin(115200);
  Serial.println("Ready. v2");
   
  //Display Stuff
  tft.init();
  tft.setRotation(4);
  tft.fillScreen(TFT_BLACK); // Bildschirm schwart loeschen

  PS4.begin("3c:71:bf:c8:02:c2");
  Serial.println("PS4 ready");


  //PWM Motor Stuff
  analogWriteFrequency(10000);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(EnB, OUTPUT);

  //Ultraschallsensoren Stuff
  //Ultraschallsensor 1
  pinMode(TRIG_PIN_1, OUTPUT);
  pinMode(ECHO_PIN_1, INPUT);
  //Ultraschallsensor 2
  pinMode(TRIG_PIN_2, OUTPUT);
  pinMode(ECHO_PIN_2, INPUT);
}


void loop() {
  //PS4 verbinden
  if (PS4.isConnected()) {
      Serial.println("PS4 connected.");

      
      //Ultraschallsensoren1 Stuff
      hindernis1 = ultraschallmessung(TRIG_PIN_1,ECHO_PIN_1,hindernis1);
      if (DEBUG) { Serial.printf("Entfernung zum Hindernis Sensor1: %lu \n", hindernis1); }
    
      //Ultraschallsensoren2 Stuff
      hindernis2 = ultraschallmessung(TRIG_PIN_2,ECHO_PIN_2,hindernis2);
      if (DEBUG) { Serial.printf("Entfernung zum Hindernis Sensor2: %lu \n", hindernis2); }
      
      if (DEBUG) { Serial.printf("Entfernungsmessung: Distanz1 %d - Distanz2 %d \n", hindernis1, hindernis2); }

           
      // Display
      display();

      
      //PWM Wert ausgeben
      Serial.printf("Der PWM-Wert ist: %d\n", pwmwert);

       
      if( (hindernis1<20) || (hindernis2<20) )
      {
        stop_motors();
      }
      else {
      
      //Vorwärts fahren
      if (PS4.Up()){
        forward(); 
        Serial.println("Up Button");
        tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
        tft.print("Nach Vorne  ");   
        }
        //rückwärts fahren
        else if (PS4.Down()){
          backward();
          Serial.println("Down Button");
          tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
          tft.print("Nach Hinten "); 
        }
        //Nach Links fahren
        else if (PS4.Left()){
          turn_left();
          Serial.println("Left Button"); 
          tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
          tft.print("Nach Links  ");
        }
        //Nach rechts drehen
        else if (PS4.Right()){
          turn_right();
          Serial.println("Right Button");
          tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
          tft.print("Nach Rechts "); 
        }
        //Nach Links fahren
        else if (PS4.Square()){
          turn_left_back();
          Serial.println("Square"); 
          tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
          tft.print("Nach Links  ");
        }
        //Nach rechts drehen
        else if (PS4.Circle()){
          turn_right_back();
          Serial.println("Circle");
          tft.setTextColor(TFT_RED,TFT_BLACK);  tft.setTextSize(2);
          tft.print("Nach Rechts "); 
        }
        //4 Geschwindigkeitsgänge
        else if(PS4.L1()) {
          pwmwert = 150;
        }
        else if(PS4.L2()) {
          pwmwert = 175;
        }
        else if (PS4.R1()) {
          pwmwert = 200;
        }
        else if(PS4.R2()) {
          pwmwert = 225;
        }
        else{
          stop_motors();
        }
      
      }  
        
    } 
    
  }
  
