#include <iostream>

// Thêm thư viện
#include "parser.h"

int main(int argc, char* argv[]) {
  std::cout << "Bắt đầu kiểm thử thư viện tuarg\n";

  // Viết test ở đây :)
  Tuarg::TuargParser parser = Tuarg::TuargParser();

  parser.addOption("-h");
  parser.parse(argc, argv);

  const Tuarg::TuargParserOptions& options = parser.getOptions();

  for (const auto& optionPair : options) {
    std::cout << optionPair.first << " : " << optionPair.second << std::endl;
  }

  std::cout << "Kết thúc kiểm thử thư viện\n";
  return 0;
}