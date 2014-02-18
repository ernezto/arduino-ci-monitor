#ifndef StartingBuildCommand_h
#define StartingBuildCommand_h

#include "Command.h"

class StartingBuildCommand : public Command {
  public:
    StartingBuildCommand(Player *player, LiquidCrystal *lcd, int light);
    void Execute();
};

#endif
