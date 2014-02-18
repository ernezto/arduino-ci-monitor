#include "PassedBuildCommand.h"
#include <Arduino.h>

PassedBuildCommand::PassedBuildCommand(Player *player, LiquidCrystal *lcd, int light) 
:  Command(player, lcd, light)
{
}

void PassedBuildCommand::Execute() {
  _lcd->clear();
  _lcd->print(_text);
  digitalWrite(_light, HIGH);
  _player->playMarioFlagPole();
}

