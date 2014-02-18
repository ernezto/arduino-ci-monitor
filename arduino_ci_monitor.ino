#include <LiquidCrystal.h>
#include "CommandFactory.h"


int buzzerPin = 7;
int green_light = 10; 
int red_light = 9; 
int blue_light = 13;
char inputCommand[32] = "";


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
CommandFactory factory(red_light, green_light, blue_light, buzzerPin, &lcd);

void setup() {
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
  Serial.begin(9600);   // start Arduino serial monitor at 9600bps
  pinMode(green_light, OUTPUT); 
  pinMode(red_light, OUTPUT);
  pinMode(blue_light, OUTPUT); 
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int isBlueActive = digitalRead(blue_light);
  if (isBlueActive == 1)
    strobe(blue_light);
  delay(300);
}

void strobe(int led) {
  digitalWrite(led, LOW);
  delay(300);               
  digitalWrite(led, HIGH);
  delay(300);            
}

void turnOffLights() {
  digitalWrite(green_light, LOW);
  digitalWrite(blue_light, LOW);
  digitalWrite(red_light, LOW);
}

void serialEvent() {
  if (Serial.available()) {
    turnOffLights();
    readSerialInput();
  }
}

void readSerialInput(){
  char inputCommand[255] = "";
  while(Serial.available()) {
    int count = Serial.readBytes(inputCommand, 255);
    inputCommand[count] = '\0';
    Command *command = factory.getCommandFromString(inputCommand);
    command->Execute();
  } 
}


