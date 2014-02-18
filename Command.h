#ifndef _Command_h
#define _Command_h

#include "Player.h"
#include <LiquidCrystal.h>

class Command {
  public:
    Command(Player *player, LiquidCrystal *lcd, int light);
    void setText(String text);
    virtual void Execute() = 0;
  
  protected:
    Player *_player;
    LiquidCrystal *_lcd;
    String _text;
    int _light;
};

#endif
