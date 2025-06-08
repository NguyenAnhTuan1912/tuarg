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

void Tuarg::Utils::ltrim(std::string& str) {
  str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
    return !std::isspace(ch);
  }));
};

void Tuarg::Utils::rtrim(std::string& str) {
  str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
    return !std::isspace(ch);
  }).base(), str.end());
};

void Tuarg::Utils::trim(std::string& str) {
  Tuarg::Utils::ltrim(str);
  Tuarg::Utils::rtrim(str);
};