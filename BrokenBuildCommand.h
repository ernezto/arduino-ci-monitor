#ifndef BrokenBuildCommand_h
#define BrokenBuildCommand_h

#include "Command.h"

class BrokenBuildCommand : public Command {
  public:
    BrokenBuildCommand(Player *player, LiquidCrystal *lcd);
    void Execute();
};

#endif
