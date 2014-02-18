#ifndef _Command_h
#define _Command_h

#include "Player.h"
#include <LiquidCrystal.h>

class Command {
  public:
    Command(Player *player, LiquidCrystal *lcd);
    virtual void Execute() = 0;
  
  protected:
    Player *_player;
    LiquidCrystal *_lcd;
};

#endif
