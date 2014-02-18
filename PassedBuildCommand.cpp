#include "PassedBuildCommand.h"

PassedBuildCommand::PassedBuildCommand(Player *player, LiquidCrystal *lcd) 
:  Command(player, lcd)
{
}

void PassedBuildCommand::Execute() {
  _lcd->print("Build Passed!!");
  _player->playMarioFlagPole();
}

