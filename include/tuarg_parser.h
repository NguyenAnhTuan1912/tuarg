#ifndef TUARG_PARSER_H
#define TUARG_PARSER_H

#include "tuarg_types.h"
#include "tuarg_option.h"
#include "tuarg_command.h"
#include "tuarg_command_group.h"

namespace Tuarg {

  using TuargParserArgMap = std::unordered_map<std::string, bool>;
  using TuargParserArgs = std::vector<std::string>;

  /**
   * @class ArgParser
   * @brief Class để xử lý parsing các đối số dòng lệnh.
   * 
   * Lớp này cung cấp chức năng thêm các flag và kiểm tra xem
   * flag nào có được truyền vào khi chạy chương trình.
   */
  class TuargParser {
    public:
      TuargParser(TuargCommandGroup& commandGroup): _commandGroup(commandGroup) {
        this->_init();
        this->_currentCommand = &this->_commandGroup.getRootCommandConstRef();
      }

      /**
       * @brief Kiểm tra xem một flag nào đó có tồn tại trong parser
       * 
       * @param name tên của flag
       * @return void
       */
      void parse(int argc, char* argv[]);

      /**
       * @brief Lấy tham chiếu của danh sách các tham số trong parser.
       */
      const TuargParserArgs& getArgs() const;

      /**
       * @brief Lấy tham chiếu của danh sách kết quả của parser.
       */
      const TuargParseResult& getResult() const;

      /**
       * @brief lấy tham chiếu của instance của command hiện tại.
       */
      const TuargCommand& getCurrentCommand() const;

      /**
       * @brief Lấy giá trị chuỗi của command hiện tại.
       */
      std::string getCurrentCommandValue();

      private:

        const TuargCommand* _currentCommand = nullptr;
        TuargCommandGroup& _commandGroup;
        TuargParserArgs _args = {};
        TuargParseResult _result = {};

        /**
         * @brief Dùng để khởi tạo một số thông tin bao đầu cho Parser,
         * bởi vì sẽ có một số thuộc tính, thông tin cần được khởi tạo
         * trước và chúng ta có thể sẽ có nhiều hàm khởi tạo khác nhau.
         */
        void _init();
  };

}

#endif