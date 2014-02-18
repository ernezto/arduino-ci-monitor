#ifndef PassedBuildCommand_h
#define PassedBuildCommand_h

#include "Command.h"

class PassedBuildCommand : public Command {
  public:
    PassedBuildCommand(Player *player, LiquidCrystal *lcd, int light);
    void Execute();
};

#endif
