#include "tuarg_option.h"

namespace Tuarg {
  TuargOption::TuargOption() {};

  TuargOption::TuargOption(const std::string& value) {
    this->value_ = value;
  };

  TuargOption::TuargOption(const std::string& value, Tuarg::EPositionalArg positionalType) {
    this->value_ = value;
    this->positionalType_ = positionalType;
  };

  TuargOption::TuargOption(
    const std::string& value,
    const std::string& shortName,
    Tuarg::EPositionalArg positionalType
  ) {
    this->value_ = value;
    this->shortName_ = shortName;
    this->positionalType_ = positionalType;
  };

  void TuargOption::setPositionalArgType(Tuarg::EPositionalArg positionalType) {
    this->positionalType_ = positionalType;
  };

  void TuargOption::setArgs(const std::vector<std::string>& args) {
    this->args_ = args;
  };
  
  void TuargOption::addArg(const std::string& arg) {
    this->args_.push_back(arg);
  };

  std::string TuargOption::getValue() const {
    return this->value_;
  };

  std::string TuargOption::getShortName() const {
    return this->shortName_;
  };

  Tuarg::EPositionalArg TuargOption::getPositionalType() const {
    return this->positionalType_;
  };

  const std::vector<std::string>& TuargOption::getArgs() const {
    return this->args_;
  };
}