#include "tuarg_flag.h"

namespace Tuarg {
  TuargFlag::TuargFlag() {}

  TuargFlag::TuargFlag(const std::string& name) {
    this->name_ = name;
  };

  TuargFlag::TuargFlag(const std::string& name, const std::string& shortName) {
    this->name_ = name;
    this->shortName_ = shortName;
  };
  
  std::string TuargFlag::getShortName() const {
    return this->shortName_;
  };

  std::string TuargFlag::getName() const {
    return this->name_;
  };
}