#include <iostream>

// Thêm thư viện
#include "tuarg_parser.h"

int main(int argc, char* argv[]) {
  std::cout << "Bắt đầu kiểm thử thư viện tuarg\n";

  // Viết test ở đây :)
  Tuarg::TuargParser parser = Tuarg::TuargParser();

  parser.addCommand(
    "add",
    {
      { "help", "h" }
    },
    {
      { "operands", "opds", Tuarg::EPositionalArg::Required }
    }    
  );

  std::cout << "Bắt đầu phân tích tham số\n";

  parser.parse(argc, argv);

  std::cout << "Phân tích tham số xong\n";

  const Tuarg::TuargParserArgs& args = parser.getArgs();

  for (const std::string& arg : args) {
    std::cout << arg << std::endl;
  }

  std::cout << "Kết thúc kiểm thử thư viện\n";
  return 0;
}