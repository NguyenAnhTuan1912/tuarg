#include <iostream>

#include "tuarg_command.h"

namespace Tuarg {
  TuargCommand::TuargCommand() {};

  TuargCommand::TuargCommand(const std::string& commandName) {
    this->value_ = commandName;
  };

  void TuargCommand::addOptionDefinition(
    const std::string& name,
    const std::string& shortName,
    EPositionalArg positionalType
  ) {
    TuargOption tuargOption = TuargOption(name, shortName, positionalType);

    this->optionMap_["--" + name] = std::make_shared<TuargOption>(tuargOption);
    this->optionMap_["-" + shortName] = std::make_shared<TuargOption>(tuargOption);
  };

  void TuargCommand::addOptionDefinition(const TuargOption& tuargOption) {
    this->optionMap_["--" + tuargOption.getName()] = std::make_shared<TuargOption>(tuargOption);
    this->optionMap_["-" + tuargOption.getShortName()] = std::make_shared<TuargOption>(tuargOption);
  };

  void TuargCommand::addFlagDefinition(
    const std::string& name,
    const std::string& shortName
  ) {
    TuargFlag tuargFlag = TuargFlag(name, shortName);

    this->flagMap_["--" + name] = std::make_shared<TuargFlag>(tuargFlag);
    this->flagMap_["-" + shortName] = std::make_shared<TuargFlag>(tuargFlag);
  };

  void TuargCommand::addFlagDefinition(const TuargFlag& tuargFlag) {
    this->flagMap_["--" + tuargFlag.getName()] = std::make_shared<TuargFlag>(tuargFlag);
    this->flagMap_["-" + tuargFlag.getShortName()] = std::make_shared<TuargFlag>(tuargFlag);
  };

  std::string TuargCommand::getValue() const {
    return this->value_;
  };

  const TuargOptionMap& TuargCommand::getOptionMap() {
    return this->optionMap_;
  };

  const TuargFlagMap& TuargCommand::getFlagMap() {
    return this->flagMap_;
  };
}