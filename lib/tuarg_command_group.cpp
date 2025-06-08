#include <iostream>

#include "tuarg_command_group.h"

namespace Tuarg {
  TuargCommandGroup::TuargCommandGroup() {
    this->_commandMap = {};
  }

  void TuargCommandGroup::addRootCommand(TuargCommand& command) {
    this->_rootCommand = command;
  };

  void TuargCommandGroup::addRootCommandDefinition(
    const std::string& command,
    const std::vector<TuargFlag>& flags,
    const std::vector<TuargOption>& options
  ) {
    this->_rootCommand = TuargCommand(command);

    for (const TuargFlag& flag : flags) {
      this->_rootCommand.addFlag(flag);
    }

    for (const TuargOption& option : options) {
      this->_rootCommand.addOption(option);
    }
  };

  void TuargCommandGroup::addCommand(TuargCommand& command) {
    std::string commandName = command.getValueCopy();
    
    if (this->_commandMap.count(commandName)) {
      std::cout << "Cannot add the command " << commandName << ". Because it was added.\n";
      return;
    }

    this->_commandMap[commandName] = command;
  };

  void TuargCommandGroup::addCommandDefinition(
    const std::string& commandName,
    const std::vector<TuargFlag>& flags,
    const std::vector<TuargOption>& options
  ) {
    TuargCommand command = TuargCommand(commandName);

    for (const TuargFlag& flag : flags) {
      command.addFlag(flag);
    }

    for (const TuargOption& option : options) {
      command.addOption(option);
    }

    if (this->_commandMap.count(commandName)) {
      std::cout << "Cannot add the command " << commandName << ". Because it was added.\n";
      return;
    }

    this->_commandMap[commandName] = command;
  };

  const TuargCommand& TuargCommandGroup::getRootCommandConstRef() const {
    return this->_rootCommand;
  };

  const TuargCommandMap& TuargCommandGroup::getCommandMapConstRef() const {
    return this->_commandMap;
  };
}