#include <iostream>

#include "tuarg_parser.h"

namespace Tuarg {
  void TuargParser::_init() {}

  void TuargParser::parse(int argc, char* argv[]) {
    // Phần tử đầu tiên có thể là:
    // 1. Command. Ví dụ: add, sub, ...
    // 2. Option. Ví dụ: -opds, --operands, ...
    // 3. Flags. Ví dụ: -h, -v, --help, ...

    std::string firstArg = argv[1];
    int startIndex = 1;

    const TuargCommandMap& commandMap = this->_commandGroup.getCommandMapConstRef();

    // std::cout << "First argument: " << firstArg << std::endl;

    // Nếu first argument là command
    if (firstArg.rfind("-", 0) != 0 && firstArg.rfind("--", 0) != 0) {
      if (commandMap.count(firstArg)) {
        auto it = commandMap.find(firstArg);
        if (it != commandMap.end()) {
            this->_currentCommand = &it->second;
        } else {
            this->_currentCommand = nullptr;
            throw std::runtime_error("Command not found: " + firstArg);
        }
        startIndex = 2;
      } else 
        throw std::invalid_argument("Command " + firstArg + " isn't a valid command.");
    }

    const Tuarg::TuargOptionMap& optionMap = (*this->_currentCommand).getOptionMapConstRef();
    const Tuarg::TuargFlagMap& flagMap = (*this->_currentCommand).getFlagMapConstRef();
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
          if (optionValues.size() > 1 && _result.find(currentOptionName) == _result.end()) {
            _result[currentOptionName] = optionValues;
          }

          tuargOption = *(optionMap.at(arg));

          currentOptionName = tuargOption.getName();
          optionValues = {};
          _args.push_back(arg);
          continue;
        }
        // Kiểm tra xem có phải là flag không?
        if (flagMap.count(arg)) {
          tuargFlag = *(flagMap.at(arg));
          std::string flagName = tuargFlag.getName();

          // Nếu như flag chưa có trong kết quả, thì thêm vào
          if (_result.find(flagName) == _result.end()) {
            _result[flagName] = true;
          }
          // Nếu như có rồi thì có nghĩa là bị lặp => ném lỗi
          else {
            throw std::invalid_argument("The flag " + arg + " is repeated.");
          }

          _args.push_back(arg);
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

        if (_result.find(currentOptionName) == _result.end())
          _result[currentOptionName] = optionValues;
        
        // Làm mới lại các giá trị
        optionValues = {};
        currentOptionName = "";
      } else if (tuargOption.getPositionalType() == EPositionalArg::Many) {
        optionValues.push_back(arg);
      } else {
        throw std::runtime_error("The number values of " + currentOptionName + " is exceeded.");
      }

      _args.push_back(arg);
    }
  };

  const TuargParserArgs& TuargParser::getArgs() const {
    return this->_args;
  };

  const TuargParseResult& TuargParser::getResult() const {
    return this->_result;
  };

  std::string TuargParser::getCurrentCommandValue() {
    return this->_currentCommand->getValueCopy();
  };

  const TuargCommand& TuargParser::getCurrentCommand() const {
    return *(this->_currentCommand);
  };
}