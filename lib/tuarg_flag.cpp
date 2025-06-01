#include "tuarg_flag.h"

namespace Tuarg {
  TuargFlag::TuargFlag() {}

  TuargFlag::TuargFlag(const std::string& value) {
    this->value_ = value;
  };

  TuargFlag::TuargFlag(const std::string& value, const std::string& shortName) {
    this->value_ = value;
    this->shortName_ = shortName;
  };
  
  std::string TuargFlag::getShortName() const {
    return this->shortName_;
  };

  std::string TuargFlag::getValue() const {
    return this->value_;
  };
}