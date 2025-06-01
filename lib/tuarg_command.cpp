#include "tuarg_command.h"

namespace Tuarg {
  TuargCommand::TuargCommand() {};

  TuargCommand::TuargCommand(const std::string& value) {
    this->value_ = value;
  };

  void TuargCommand::addOptionDefinition(
    const std::string& value,
    const std::string& shortName,
    EPositionalArg positionalType
  ) {
    TuargOption tuargOption = TuargOption(value, shortName, positionalType);

    this->optionsMap_["--" + value] = std::make_shared<TuargOption>(tuargOption);
    this->optionsMap_["-" + shortName] = std::make_shared<TuargOption>(tuargOption);
  };

  void TuargCommand::addOptionDefinition(const TuargOption& tuargOption) {
    this->optionsMap_["--" + tuargOption.getValue()] = std::make_shared<TuargOption>(tuargOption);
    this->optionsMap_["-" + tuargOption.getShortName()] = std::make_shared<TuargOption>(tuargOption);
  };

  void TuargCommand::addFlagDefinition(
    const std::string& value,
    const std::string& shortName
  ) {
    TuargFlag tuargFlag = TuargFlag(value, shortName);

    this->flagMap_["--" + value] = std::make_shared<TuargFlag>(tuargFlag);
    this->flagMap_["-" + shortName] = std::make_shared<TuargFlag>(tuargFlag);
  };

  void TuargCommand::addFlagDefinition(const TuargFlag& tuargFlag) {
    this->flagMap_["--" + tuargFlag.getValue()] = std::make_shared<TuargFlag>(tuargFlag);
    this->flagMap_["-" + tuargFlag.getShortName()] = std::make_shared<TuargFlag>(tuargFlag);
  };

  std::string TuargCommand::getValue() const {
    return this->value_;
  };
}