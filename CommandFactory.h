#ifndef CommandFactory_h
#define CommandFactory_h

#include "BrokenBuildCommand.h"
#include "Command.h"

class CommandFactory {
  public:
    CommandFactory(int red_light, int green_light, int blue_light, int buzzerPin, LiquidCrystal *lcd);
    Command *getCommandFromString(String input);
    String getPrintVersion();
  
  private:
    void parseInput(String input);
    bool isBrokenCommand();
    bool isPassedCommand();
    bool isStartingCommand();    
    
    int _command;
    String _text;
    LiquidCrystal *_lcd;
    Player *_player;
    Command *brokenBuild;
    Command *passedBuild;
    Command *startingBuild;
};

#endif

