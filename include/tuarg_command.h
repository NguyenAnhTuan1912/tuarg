#ifndef TUARG_COMMAND_H
#define TUARG_COMMAND_H

#include "tuarg_types.h"
#include "tuarg_option.h"
#include "tuarg_flag.h"

namespace Tuarg {
  class TuargCommand;
  using TuargCommandMap = std::unordered_map<std::string, TuargCommand>;
  
  /**
   * @class TuargCommand
   * @brief Class dùng để quản lý command
   * 
   * Trong một command có thể sẽ có các flags hay options
   * và chúng ta sẽ cần phải quản lý các thông tin đó.
   */
  class TuargCommand {
    public:

      TuargCommand();
      TuargCommand(const std::string& commandName);

      /**
       * @brief Thêm một option mới vào trong danh sách với
       * một số thông tin cơ bản của option.
       * 
       * @param name giá trị thực của option
       * @param shortName tên ngắn đại diện cho option
       * @param longName tên dài đại diện cho option
       * @param positionalType kiểu positional argument
       */
      void addOptionDefinition(
        const std::string& name,
        const std::string& shortName,
        EPositionalArg positionalType = EPositionalArg::OnlyOne
      );

      /**
       * @brief Thêm một option mới vào trong danh sách.
       * 
       * @param tuargOption instance cuar TuargOption
       */
      void addOptionDefinition(const TuargOption& tuargOption);

      /**
       * @brief Thêm một flag mới vào trong danh sách với các thông tin
       * cơ bản của flag.
       * 
       * @param name giá trị thực của flag.
       * @param shortName tên ngắn của flag.
       */
      void addFlagDefinition(
        const std::string& name,
        const std::string& shortName
      );

      /**
       * @brief Thêm một flag mới vào trong danh sách.
       */
      void addFlagDefinition(const TuargFlag& tuargFlag);

      /**
       * @brief Lấy giá trị thực của command.
       */
      std::string getValue() const;

      /**
       * @brief Lấy tham chiếu của danh sách các options
       */
      const TuargOptionMap& getOptionMap();

      /**
       * @brief Lấy tham chiếu của danh sách các flags
       */
      const TuargFlagMap& getFlagMap();

    private:

      std::string value_;
      TuargOptionMap optionMap_;
      TuargFlagMap flagMap_;
  };

}

#endif