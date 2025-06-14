#ifndef TUARG_TYPES_H
#define TUARG_TYPES_H

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <variant>

namespace Tuarg {
  enum class EPositionalArg {
    OnlyOne,
    Many
  };
  using TuargParseResult = std::unordered_map<std::string, std::variant<std::vector<std::string>, bool>>;
  using TuargParserDescription = std::array<std::string, 2>;
  using TuargParserDescriptions = std::vector<std::array<std::string, 2>>;
}

#endif