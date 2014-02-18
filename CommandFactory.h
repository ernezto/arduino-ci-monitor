#ifndef CommandFactory_h
#define CommandFactory_h

#include "BrokenBuildCommand.h"
#include "Command.h"

class CommandFactory {
  public:
    Command *getCommandFromString(String input);
};

#endif

