#ifndef TUARG_PARSER_H
#define TUARG_PARSER_H

#include "tuarg_types.h"
#include "tuarg_option.h"
#include "tuarg_command.h"

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
      TuargParser();

      /**
       * @brief Kiểm tra xem một flag nào đó có tồn tại trong parser
       * 
       * @param name tên của flag
       * @return void
       */
      void parse(int argc, char* argv[]);

      /**
       * @brief Thêm một command mới vào trong parser với một số
       * thông tin cơ bản của command.
       * 
       * @param command giá trị của command, được dùng trong cli.
       * @param flags một danh sách đề mục các flags của command.
       * @param options một danh sách đề mục các options của command.
       */
      void addCommand(
        const std::string& command,
        const std::vector<TuargFlag>& flags,
        const std::vector<TuargOption>& options
      );

      /**
       * @brief Thêm một command mới vào trong parser.
       * 
       * @param tuargCommand instance của tuargCommand
       */
      void addCommand(TuargCommand& tuargCommand);

      /**
       * @brief Lấy tham chiếu của danh sách các tham số trong parser.
       */
      const TuargParserArgs& getArgs() const;

      /**
       * @brief Lấy tham chiếu của danh sách kết quả của parser.
       */
      const TuargParseResult& getResult() const;

      private:

        TuargCommand* currentCommand_ = nullptr;
        TuargCommandMap commandMap_;
        TuargParserArgs args_;
        TuargParseResult result_;
  };

}

#endif