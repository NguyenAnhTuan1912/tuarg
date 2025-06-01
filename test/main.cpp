#include <iostream>

// Thêm thư viện
#include "tuarg_parser.h"
#include "tuarg_utils.h"

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
      { "operands", "opds", Tuarg::EPositionalArg::Many }
    }
  );

  std::cout << "Bắt đầu phân tích tham số\n";

  parser.parse(argc, argv);

  std::cout << "Phân tích tham số xong\n";

  std::cout << "\nCác tham số đã phân tích\n";
  const Tuarg::TuargParserArgs& args = parser.getArgs();

  for (const std::string& arg : args) {
    std::cout << arg << std::endl;
  }

  std::cout << "\nKết quả cuối cùng\n";
  Tuarg::Utils::printTuargParseResult(parser.getResult());

  std::cout << "\nKết thúc kiểm thử thư viện\n";
  return 0;
}