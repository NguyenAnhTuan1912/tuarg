#include "tuarg_utils.h"

void Tuarg::Utils::printTuargParseResult(const TuargParseResult& result) {
  for (const auto& [key, value] : result) {
    // In key (first) ra trước
    std::cout << key << ": ";
    // Nếu như value (second) là std::vector<std::string>
    if (std::holds_alternative<std::vector<std::string>>(value)) {
      const auto& vec = std::get<std::vector<std::string>>(value);

      std::cout << "[ ";
      for (const auto& str : vec) {
        std::cout << str << " ";
      }
      std::cout << "]\n";
    }
    // Nếu như value (second) là bool
    else {
      std::cout << (std::get<bool>(value) ? "true" : "false") << "\n";
    }
  }
}