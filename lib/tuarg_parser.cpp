#include <iostream>

#include "tuarg_parser.h"

namespace Tuarg {
  TuargParser::TuargParser() {
    this->args_ = {};
    this->commandMap_ = {};
    TuargCommand rootCommand = TuargCommand("root");

    rootCommand.addFlagDefinition("help", "h");

    this->currentCommand_ = &rootCommand;

    commandMap_[rootCommand.getValue()] = rootCommand;
  };

  void TuargParser::parse(int argc, char* argv[]) {
    // Phần tử đầu tiên có thể là:
    // 1. Command. Ví dụ: add, sub, ...
    // 2. Option. Ví dụ: -opds, --operands, ...
    // 3. Flags. Ví dụ: -h, -v, --help, ...

    std::string firstArg = argv[1];

    // std::cout << "First argument: " << firstArg << std::endl;

    // Nếu first argument là command
    if (firstArg.rfind("-", 0) != 0 && firstArg.rfind("--", 0) != 0) {
      if (this->commandMap_.count(firstArg)) {
        this->currentCommand_ = &this->commandMap_[firstArg];
      } else 
        throw std::invalid_argument("Command " + firstArg + " isn't a valid command.");
    }

    // Xây dựng các options và flags cho command
    for (int i = 2; i < argc; ++i) {
      std::string arg = argv[i];
      args_.push_back(arg);
    }
  };

  void TuargParser::addCommand(
    const std::string& command,
    const std::vector<TuargFlag>& flags,
    const std::vector<TuargOption>& options
  ) {
    TuargCommand tuargCommand = TuargCommand(command);

    for (const TuargFlag& flag : flags) {
      tuargCommand.addFlagDefinition(flag);
    }

    for (const TuargOption& option : options) {
      tuargCommand.addOptionDefinition(option);
    }

    if (commandMap_.count(command)) {
      std::cout << "Cannot add the command " << command << ". Because it was added.\n";
      return;
    }

    commandMap_[command] = tuargCommand;
  };

  void TuargParser::addCommand(TuargCommand& tuargCommand) {
    std::string command = tuargCommand.getValue();

    if (commandMap_.count(command)) {
      std::cout << "Cannot add the command " << command << ". Because it was added.\n";
      return;
    }

    commandMap_[command] = tuargCommand;
  };

  const TuargParserArgs& TuargParser::getArgs() const {
    return this->args_;
  };
}