#include "Command.h"


Command::Command(Player *player, LiquidCrystal *lcd) {
  _lcd = lcd;
  _player = player;
}


