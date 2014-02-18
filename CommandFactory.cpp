#include "CommandFactory.h"

CommandFactory::CommandFactory(Player *player, LiquidCrystal *lcd) {
  _lcd = lcd;
  _player = player;
}

Command *CommandFactory::getCommandFromString(String input) {
  return 0;
}

