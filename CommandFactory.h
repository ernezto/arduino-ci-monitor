#ifndef CommandFactory_h
#define CommandFactory_h

#include "BrokenBuildCommand.h"
#include "Command.h"

class CommandFactory {
  public:
    CommandFactory(Player *player, LiquidCrystal *lcd);
    Command *getCommandFromString(String input);
  
  private:
    LiquidCrystal *_lcd;
    Player *_player;
};

#endif

