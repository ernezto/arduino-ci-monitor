
#include <LiquidCrystal.h>
#include "Player.h"
#include "BrokenBuildCommand.h"
#include "StartingBuildCommand.h"


int melodyPin = 7;
int green_light = 10; 
int red_light = 9; 
int blue_light = 13;
int command = 0;
boolean canPlay = true;
char inputCommand[32] = "";

Player player;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
BrokenBuildCommand brokenBuild(&player, &lcd);
StartingBuildCommand startingBuild(&player, &lcd);



void setup() {
  lcd.begin(16, 2);    // set up the LCD's number of columns and rows: 
  Serial.begin(9600);   // start Arduino serial monitor at 9600bps
  pinMode(green_light, OUTPUT); 
  pinMode(red_light, OUTPUT);
  pinMode(blue_light, OUTPUT); 
  pinMode(melodyPin, OUTPUT);
  player.setBuzzerPin(melodyPin);
}

void loop() {
  // the serial bits “49” - “53” are detected when the numeric buttons “1” – “5” are pressed on the keyboard.
  // 1 - To turn on yellow light
  // 2 - To blink yellow light
  // 3 - To turn on red light
  // 4 - To blink red light
  // 5 - To turn off all the lights
  switch (command){
     case 49: // 1
       digitalWrite(blue_light, HIGH);
       digitalWrite(red_light, LOW);
       break;
     case 50: // 2 
       strobe(blue_light);
       startingBuild.Execute();
       break;
     case 51: // 3
       digitalWrite(blue_light, LOW);     
       digitalWrite(red_light, HIGH);
       brokenBuild.Execute();
       break;
     case 52: // 4
       strobe(red_light);
       break;
     case 53:  // 5
       turnOffLights();
       break;
  }
}

//void brokenBuild(){
//  if (canPlay)
//  player.playMarioFlagPole();
//  canPlay = false;
//  
//}

void strobe(int led) {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(300);               // wait for a second
}

void turnOffLights() {
  digitalWrite(green_light, LOW);
  digitalWrite(blue_light, LOW);
  digitalWrite(red_light, LOW);
}

void serialEvent() {
  if (Serial.available()) {
    readSerialInput();
    canPlay = true;
  }
}

void readSerialInput(){
  char inputCommand[32] = "";
  while(Serial.available()) {
    int count = Serial.readBytes(inputCommand, 32);
    inputCommand[count] = '\0';
    command = parseCommand(inputCommand);
    printLCD(inputCommand);
  } 
}

int parseCommand(char input[32]) {
  Serial.println(input);
  int length = strlen(input);
  Serial.println(length);
  if (length == 1)
    return (int)input[0];
  return 0;
}

void printLCD(String text) {
  if (command == 0){
    lcd.clear();
    lcd.print(text);
  } 
}

