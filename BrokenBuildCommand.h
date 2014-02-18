#ifndef BrokenBuildCommand_h
#define BrokenBuildCommand_h

#include "Command.h"

class BrokenBuildCommand : public Command {
  public:
    BrokenBuildCommand(Player *player, LiquidCrystal *lcd, int light);
    void Execute();
};

#endif
