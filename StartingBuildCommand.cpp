#include "StartingBuildCommand.h"
#include <Arduino.h>

StartingBuildCommand::StartingBuildCommand(Player *player, LiquidCrystal *lcd, int light) 
:  Command(player, lcd, light)
{
}

void StartingBuildCommand::Execute() {
  digitalWrite(_light, HIGH);
  _lcd->clear();
  _lcd->print(_text);
  _player->playMarioTheme();

}
