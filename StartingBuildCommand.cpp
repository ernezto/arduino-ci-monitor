#include "StartingBuildCommand.h"

StartingBuildCommand::StartingBuildCommand(Player *player, LiquidCrystal *lcd) 
:  Command(player, lcd)
{
}

void StartingBuildCommand::Execute() {
  _lcd->print("Build starting");
  _player->playMarioTheme();

}
