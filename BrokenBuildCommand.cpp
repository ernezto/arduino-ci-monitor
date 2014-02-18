#include "BrokenBuildCommand.h"
#include <Arduino.h>

BrokenBuildCommand::BrokenBuildCommand(Player *player, LiquidCrystal *lcd, int light) 
:  Command(player, lcd, light)
{
}

void BrokenBuildCommand::Execute() {
  digitalWrite(_light, HIGH);
  _lcd->clear();
  _lcd->print(_text);
  _player->playMarioDeath();

}

