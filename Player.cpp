#include "Player.h"
#include <Arduino.h>

Player::Player(int buzzerPin) {
  _buzzerPin = buzzerPin;
}

void Player::setBuzzerPin(int buzzerPin){
  _buzzerPin = buzzerPin;
}

void Player::playMarioDeath() {
  play(death);
}

void Player::playMarioFlagPole() {
 play(flagpole);
}

void Player::playMarioTheme() {
  play(theme);
}

void Player::playMarioGameOver() {
  play(gameover);
}

void Player::play(const int melody[]) {
  for (int i = 1; i < (melody[0] * 2 + 1); i += 2) { 
    tone(_buzzerPin, melody[i], (1000/melody[i + 1]));
    delay((1000/melody[i + 1]) * 1.30);                
    noTone(_buzzerPin);                                  
  }
}



