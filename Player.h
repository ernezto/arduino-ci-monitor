#ifndef _Player_h
#define _Player_h

#include "melodies.h"

class Player {
  
  public:
    Player(int buzzerPin);
    void playMarioDeath();
    void playMarioFlagPole();
    void playMarioGameOver();
    void playMarioTheme();
    
    void setBuzzerPin(int buzzerPin);

  private:
    int _buzzerPin;
    void play(const int melody[]);
};

#endif

