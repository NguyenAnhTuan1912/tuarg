#include <iostream>
#include <iomanip>

#include "tuarg_command.h"
#include "tuarg_utils.h"

namespace Tuarg {
  TuargCommand::TuargCommand() {};

  TuargCommand::TuargCommand(const std::string& commandName) {
    this->_value = commandName;
  };

  TuargCommand::TuargCommand(const std::string& commandName, const std::string& description) {
    this->_value = commandName;
    this->_description = description;
  };

  void TuargCommand::addOptionDefinition(
    const std::string& name,
    const std::string& shortName,
    EPositionalArg positionalType,
    const std::string& description
  ) {
    TuargOption tuargOption = TuargOption(name, shortName, positionalType, description);

    std::string fullArgOptionName = "--" + name;
    std::string fullArgOptionShortName = "-" + shortName;

    if (fullArgOptionName.length() > this->_longestNameLength)
      this->_longestNameLength = fullArgOptionName.length();

    if (fullArgOptionShortName.length() > this->_longestShortNameLength)
      this->_longestShortNameLength = fullArgOptionShortName.length();

    std::shared_ptr<TuargOption> sharedPtrTuargOption = std::make_shared<TuargOption>(tuargOption);
    this->_optionMap[fullArgOptionName] = sharedPtrTuargOption;
    this->_optionMap[fullArgOptionShortName] = sharedPtrTuargOption;
  };

  void TuargCommand::addOption(const TuargOption& tuargOption) {
    std::string fullArgOptionName = "--" + tuargOption.getName();
    std::string fullArgOptionShortName = "-" + tuargOption.getShortName();

    if (fullArgOptionName.length() > this->_longestNameLength)
      this->_longestNameLength = fullArgOptionName.length();

    if (fullArgOptionShortName.length() > this->_longestShortNameLength)
      this->_longestShortNameLength = fullArgOptionShortName.length();

    std::shared_ptr<TuargOption> sharedPtrTuargOption = std::make_shared<TuargOption>(tuargOption);
    this->_optionMap[fullArgOptionName] = sharedPtrTuargOption;
    this->_optionMap[fullArgOptionShortName] = sharedPtrTuargOption;
  };

  void TuargCommand::addFlagDefinition(
    const std::string& name,
    const std::string& shortName,
    const std::string& description
  ) {
    TuargFlag tuargFlag = TuargFlag(name, shortName, description);

    std::string fullArgFlagName = "--" + name;
    std::string fullArgFlagShortName = "-" + shortName;

    if (fullArgFlagName.length() > this->_longestNameLength)
      this->_longestNameLength = fullArgFlagName.length();

    if (fullArgFlagShortName.length() > this->_longestShortNameLength)
      this->_longestShortNameLength = fullArgFlagShortName.length();

    std::shared_ptr<TuargFlag> sharedPtrTuargFlag = std::make_shared<TuargFlag>(tuargFlag);
    this->_flagMap[fullArgFlagName] = sharedPtrTuargFlag;
    this->_flagMap[fullArgFlagShortName] = sharedPtrTuargFlag;
  };

  void TuargCommand::addFlag(const TuargFlag& tuargFlag) {
    std::string fullArgFlagName = "--" + tuargFlag.getName();
    std::string fullArgFlagShortName = "-" + tuargFlag.getShortName();

    if (fullArgFlagName.length() > this->_longestNameLength)
      this->_longestNameLength = fullArgFlagName.length();

    if (fullArgFlagShortName.length() > this->_longestShortNameLength)
      this->_longestShortNameLength = fullArgFlagShortName.length();

    std::shared_ptr<TuargFlag> sharedPtrTuargFlag = std::make_shared<TuargFlag>(tuargFlag);
    this->_flagMap[fullArgFlagName] = sharedPtrTuargFlag;
    this->_flagMap[fullArgFlagShortName] = sharedPtrTuargFlag;
  };

  std::string TuargCommand::getValueCopy() const {
    return this->_value;
  };

  const TuargOptionMap& TuargCommand::getOptionMapConstRef() const {
    return this->_optionMap;
  };

  const TuargFlagMap& TuargCommand::getFlagMapConstRef() const {
    return this->_flagMap;
  };

  void TuargCommand::setDescription(std::string description) {
    this->_description = description;
  };

  std::string TuargCommand::getDescriptionCopy() {
    return this->_description;
  };

  void TuargCommand::printDescriptionAndManual() const {
    std::cout << "Description:\n";
    std::cout << "  " << this->_description << "\n\n";

    std::cout << "Flags:\n";
    if (this->_flagMap.size() > 0) {
      TuargFlag* previous = nullptr;
      for (const auto& pair : this->_flagMap) {
        if (pair.second.get() != previous) {
          std::cout << "  " << std::left << std::setw(this->_longestShortNameLength + 2) << pair.second->getShortName() + ", ";
          std::cout << std::setw(this->_longestNameLength + 1) << pair.second->getName() + ":";
          std::cout << "   ";
          std::cout << pair.second->getDescriptionCopy() << "\n";
        }
        previous = pair.second.get();
      }
      std::cout << "\n";
    } else {
      std::cout << "  " << "N\\A" << "\n\n";
    }

    std::cout << "Options:\n";
    if (this->_optionMap.size() > 0) {
      TuargOption* previous = nullptr;
      for (const auto& pair : this->_optionMap) {
        if (pair.second.get() != previous) {
          std::cout << "  " << std::left << std::setw(this->_longestShortNameLength + 2) << pair.second->getShortName() + ", ";
          std::cout << std::setw(this->_longestNameLength + 1) << pair.second->getName() + ":";
          std::cout << "   ";
          std::cout << pair.second->getDescriptionCopy() << "\n";
        }
        previous = pair.second.get();
      }
      std::cout << "\n";
    } else {
      std::cout << "  " << "N\\A" << "\n";
    }
  };
}