#include "tuarg_option.h"

namespace Tuarg {
  TuargOption::TuargOption() {};

  TuargOption::TuargOption(const std::string& name) {
    this->name_ = name;
  };

  TuargOption::TuargOption(const std::string& name, Tuarg::EPositionalArg positionalType) {
    this->name_ = name;
    this->positionalType_ = positionalType;
  };

  TuargOption::TuargOption(
    const std::string& name,
    const std::string& shortName,
    Tuarg::EPositionalArg positionalType
  ) {
    this->name_ = name;
    this->shortName_ = shortName;
    this->positionalType_ = positionalType;
  };

  void TuargOption::setPositionalArgType(Tuarg::EPositionalArg positionalType) {
    this->positionalType_ = positionalType;
  };

  std::string TuargOption::getName() const {
    return this->name_;
  };

  std::string TuargOption::getShortName() const {
    return this->shortName_;
  };

  Tuarg::EPositionalArg TuargOption::getPositionalType() const {
    return this->positionalType_;
  };
}