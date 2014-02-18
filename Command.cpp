#include "Command.h"


Command::Command(Player *player, LiquidCrystal *lcd, int light) {
  _lcd = lcd;
  _player = player;
  _light = light;
}

void Command::setText(String text) {
  _text = text;
}


