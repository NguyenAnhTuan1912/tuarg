#include "tuarg_option.h"

namespace Tuarg {
  TuargOption::TuargOption() {};

  TuargOption::TuargOption(const std::string& name) {
    this->_name = name;
  };

  TuargOption::TuargOption(const std::string& name, Tuarg::EPositionalArg positionalType) {
    this->_name = name;
    this->positionalType_ = positionalType;
  };

  TuargOption::TuargOption(
    const std::string& name,
    const std::string& shortName,
    Tuarg::EPositionalArg positionalType
  ) {
    this->_name = name;
    this->_shortName = shortName;
    this->positionalType_ = positionalType;
  };

  TuargOption::TuargOption(
    const std::string& name,
    const std::string& shortName,
    Tuarg::EPositionalArg positionalType,
    const std::string& description
  ) {
    this->_name = name;
    this->_shortName = shortName;
    this->positionalType_ = positionalType;
    this->_description = description;
  };

  void TuargOption::setPositionalArgType(Tuarg::EPositionalArg positionalType) {
    this->positionalType_ = positionalType;
  };

  std::string TuargOption::getName() const {
    return this->_name;
  };

  std::string TuargOption::getShortName() const {
    return this->_shortName;
  };

  Tuarg::EPositionalArg TuargOption::getPositionalType() const {
    return this->positionalType_;
  };

  void TuargOption::setDescription(std::string description) {
    this->_description = description;
  };

  std::string TuargOption::getDescriptionCopy() {
    return this->_description;
  };
}