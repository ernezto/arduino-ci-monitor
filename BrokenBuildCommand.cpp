#include "BrokenBuildCommand.h"

BrokenBuildCommand::BrokenBuildCommand(Player *player, LiquidCrystal *lcd) 
:  Command(player, lcd)
{
}

void BrokenBuildCommand::Execute() {
  _lcd->print("Broken Buidl!!");
  _player->playMarioDeath();

}

