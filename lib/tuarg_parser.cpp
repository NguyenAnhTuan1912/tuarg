#include "parser.h"

namespace Tuarg {

void TuargParser::parse(int argc, char* argv[]) {
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (options_.count(arg)) {
      options_[arg] = true;
    }
  }
};

void TuargParser::addOption(const std::string& name) {
  this->options_[name] = false;
};

bool TuargParser::hasOption(const std::string& name) const {
  auto it = this->options_.find(name);
  bool isNotEnd = it != this->options_.end();
  bool doesExist = it->second;

  return isNotEnd && doesExist;
};

const Tuarg::TuargParserOptions& TuargParser::getOptions() const {
  return this->options_;
}



}