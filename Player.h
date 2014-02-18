#ifndef _Player_h
#define _Player_h

#include "melodies.h"

class Player {
  
  public:
    void playMarioDeath();
    void playMarioFlagPole();
    void playMarioGameOver();
    void playMarioTheme();
    
    void setBuzzerPin(int buzzerPin);

  private:
    int buzzerPin;
    void play(const int melody[]);
};

#endif

