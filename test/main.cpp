#include <iostream>

// Thêm thư viện
#include "tuarg_parser.h"
#include "tuarg_utils.h"

int main(int argc, char* argv[]) {
  try {
    std::cout << "Bắt đầu kiểm thử thư viện tuarg\n";

    // Viết test ở đây :)
    Tuarg::TuargCommand rootCommand = Tuarg::TuargCommand(
      "tuarg",
      "Một ví dụ sử dụng CLI Builder với Tuarg. Bạn có thể dùng tool này để build một CLI của riêng bạn trong C++!"
    );

    rootCommand.addFlag({
      "help",
      "h",
      "Hiển thị hướng dẫn sử dụng của command và mô tả của từng Flags & Options."
    });
    rootCommand.addFlag({
      "test",
      "t",
      "Đây là một flag để test tính năng in description & manual của CLI."
    });
    rootCommand.addOption({
      "testoption",
      "topt",
      Tuarg::EPositionalArg::OnlyOne,
      "Thử in option trong phần."
    });
    rootCommand.addOption({
      "random",
      "r",
      Tuarg::EPositionalArg::Many,
      "Random bất kì một số trong khoảng [a, b]"
    });

    Tuarg::TuargCommand addCommand = Tuarg::TuargCommand("add");

    addCommand.addFlag({ "help", "h" });
    addCommand.addOption({ "operands", "opds", Tuarg::EPositionalArg::Many });

    Tuarg::TuargCommandGroup commandGroup = Tuarg::TuargCommandGroup();

    commandGroup.addRootCommand(rootCommand);
    commandGroup.addCommand(addCommand);
    
    Tuarg::TuargParser parser = Tuarg::TuargParser(commandGroup);

    std::cout << "Bắt đầu phân tích tham số\n";

    parser.parse(argc, argv);

    std::cout << "Phân tích tham số xong\n";

    std::cout << "\nCác tham số đã phân tích\n";
    const Tuarg::TuargParserArgs& args = parser.getArgs();

    for (const std::string& arg : args) {
      std::cout << arg << std::endl;
    }

    std::cout << "\nKết quả cuối cùng\n";
    std::cout << "Command is [" << parser.getCurrentCommandValue() << "]\n";
    Tuarg::Utils::printTuargParseResult(parser.getResult());

    std::cout << "\nIn mô tả của command hiện tại\n";
    std::cout << "\n-----\n";
    parser.getCurrentCommand().printDescriptionAndManual();
    std::cout << "-----\n";

    std::cout << "\nKết thúc kiểm thử thư viện\n";
    return 0;
  }
  catch(const std::exception& e) {
    std::cerr << "Error:" << e.what() << "\n";
    return 1;
  }
}