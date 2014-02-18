#include "CommandFactory.h"
#include "BrokenBuildCommand.h"
#include "PassedBuildCommand.h"
#include "StartingBuildCommand.h"

CommandFactory::CommandFactory(int red_light, int green_light, int blue_light, int buzzerPin, LiquidCrystal *lcd) {
  _lcd = lcd;
  _player = new Player(buzzerPin);
  brokenBuild = new BrokenBuildCommand(_player, _lcd, red_light);
  passedBuild = new PassedBuildCommand(_player, _lcd, green_light);
  startingBuild = new StartingBuildCommand(_player, _lcd, blue_light);
}

Command *CommandFactory::getCommandFromString(String input) {
  parseInput(input);
  if (isPassedCommand()) return passedBuild;
  if (isStartingCommand()) return startingBuild;
  if (isBrokenCommand()) return brokenBuild;
  return 0;
}


String CommandFactory::getPrintVersion() {
  return (String)_command + "--/////--" + _text;
}

bool CommandFactory::isPassedCommand() {
  passedBuild->setText(_text);
  return _command == 1;
}

bool CommandFactory::isStartingCommand() {
  startingBuild->setText(_text);
  return _command == 2;
}

bool CommandFactory::isBrokenCommand() {
  brokenBuild->setText(_text);
  return _command == 3;
}

void CommandFactory::parseInput(String input) {
  int colon = input.indexOf(":");
  int comma = input.indexOf(",");
  String commandText = input.substring(colon + 1, comma);
  commandText.trim();
  _command = commandText.toInt();

  colon = input.lastIndexOf(":");
  _text = input.substring(colon + 1, input.length());
  _text.trim();
}





