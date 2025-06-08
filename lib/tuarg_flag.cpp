#include "tuarg_flag.h"

namespace Tuarg {
  TuargFlag::TuargFlag() {}

  TuargFlag::TuargFlag(const std::string& name) {
    this->_name = name;
  };

  TuargFlag::TuargFlag(const std::string& name, const std::string& shortName) {
    this->_name = name;
    this->_shortName = shortName;
  };

  TuargFlag::TuargFlag(const std::string& name, const std::string& shortName, const std::string& description) {
    this->_name = name;
    this->_shortName = shortName;
    this->_description = description;
  };
  
  std::string TuargFlag::getShortName() const {
    return this->_shortName;
  };

  std::string TuargFlag::getName() const {
    return this->_name;
  };

  void TuargFlag::setDescription(std::string description) {
    this->_description = description;
  };

  std::string TuargFlag::getDescriptionCopy() {
    return this->_description;
  };
}