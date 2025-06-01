#include <iostream>

#include "tuarg_parser.h"

namespace Tuarg {
  TuargParser::TuargParser() {
    this->args_ = {};
    this->commandMap_ = {};
    this->result_ = {};
    TuargCommand rootCommand = TuargCommand("root");

    rootCommand.addFlagDefinition("help", "h");

    commandMap_[rootCommand.getValue()] = rootCommand;

    this->currentCommand_ = &commandMap_[rootCommand.getValue()];
  };

  void TuargParser::parse(int argc, char* argv[]) {
    // Phần tử đầu tiên có thể là:
    // 1. Command. Ví dụ: add, sub, ...
    // 2. Option. Ví dụ: -opds, --operands, ...
    // 3. Flags. Ví dụ: -h, -v, --help, ...

    std::string firstArg = argv[1];
    int startIndex = 1;

    // std::cout << "First argument: " << firstArg << std::endl;

    // Nếu first argument là command
    if (firstArg.rfind("-", 0) != 0 && firstArg.rfind("--", 0) != 0) {
      if (this->commandMap_.count(firstArg)) {
        this->currentCommand_ = &this->commandMap_[firstArg];
        startIndex = 2;
      } else 
        throw std::invalid_argument("Command " + firstArg + " isn't a valid command.");
    }

    const Tuarg::TuargOptionMap& optionMap = (*this->currentCommand_).getOptionMap();
    const Tuarg::TuargFlagMap& flagMap = (*this->currentCommand_).getFlagMap();
    std::string currentOptionName;
    std::vector<std::string> optionValues;
    TuargOption tuargOption;
    TuargFlag tuargFlag;

    // Xây dựng các options và flags cho command
    for (int i = startIndex; i < argc; ++i) {
      std::string arg = argv[i];
      
      // Kiểm tra xem có phải là option hoặc flag ...
      if (arg.rfind("-", 0) == 0 || arg.rfind("--", 0) == 0) {
        // Kiểm tra xem có phải là option không?
        if (optionMap.count(arg)) {
          // Kiểm tra optionValues trước để thêm các giá trị của
          // option trước đó vào trong result và currentOptionName đã tồn tại hay chưa?
          if (optionValues.size() > 1 && result_.find(currentOptionName) == result_.end()) {
            result_[currentOptionName] = optionValues;
          }

          tuargOption = *(optionMap.at(arg));

          currentOptionName = tuargOption.getName();
          optionValues = {};
          args_.push_back(arg);
          continue;
        }
        // Kiểm tra xem có phải là flag không?
        if (flagMap.count(arg)) {
          tuargFlag = *(flagMap.at(arg));
          std::string flagName = tuargFlag.getName();

          // Nếu như flag chưa có trong kết quả, thì thêm vào
          if (result_.find(flagName) == result_.end()) {
            result_[flagName] = true;
          }
          // Nếu như có rồi thì có nghĩa là bị lặp => ném lỗi
          else {
            throw std::invalid_argument("The flag " + arg + " is repeated.");
          }

          args_.push_back(arg);
          continue;
        }
        // Nếu không có thì trả lỗi
        throw std::invalid_argument("The flag or option " + arg + " isn't valid.");
      }
      // Nếu không phải là option hay flag thì nó là argument của
      // của option
      if (
        (tuargOption.getPositionalType() == EPositionalArg::OnlyOne &&
        optionValues.size() == 0) ||
        (i == argc - 1)
      ) {
        optionValues.push_back(arg);

        if (result_.find(currentOptionName) == result_.end())
          result_[currentOptionName] = optionValues;
        
        // Làm mới lại các giá trị
        optionValues = {};
        currentOptionName = "";
      } else if (tuargOption.getPositionalType() == EPositionalArg::Many) {
        optionValues.push_back(arg);
      } else {
        throw "The number values of " + currentOptionName + " is exceeded.";
      }

      args_.push_back(arg);
    }
  };

  void TuargParser::addCommand(
    const std::string& command,
    const std::vector<TuargFlag>& flags,
    const std::vector<TuargOption>& options
  ) {
    TuargCommand tuargCommand = TuargCommand(command);

    for (const TuargFlag& flag : flags) {
      tuargCommand.addFlagDefinition(flag);
    }

    for (const TuargOption& option : options) {
      tuargCommand.addOptionDefinition(option);
    }

    if (commandMap_.count(command)) {
      std::cout << "Cannot add the command " << command << ". Because it was added.\n";
      return;
    }

    commandMap_[command] = tuargCommand;
  };

  void TuargParser::addCommand(TuargCommand& tuargCommand) {
    std::string command = tuargCommand.getValue();

    if (commandMap_.count(command)) {
      std::cout << "Cannot add the command " << command << ". Because it was added.\n";
      return;
    }

    commandMap_[command] = tuargCommand;
  };

  const TuargParserArgs& TuargParser::getArgs() const {
    return this->args_;
  };

  const TuargParseResult& TuargParser::getResult() const {
    return this->result_;
  };
}