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
      TuargCommand(const std::string& commandName, const std::string& description);

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
        EPositionalArg positionalType = EPositionalArg::OnlyOne,
        const std::string& description = ""
      );

      /**
       * @brief Thêm một option mới vào trong danh sách.
       * 
       * @param tuargOption instance cuar TuargOption
       */
      void addOption(const TuargOption& tuargOption);

      /**
       * @brief Thêm một flag mới vào trong danh sách với các thông tin
       * cơ bản của flag.
       * 
       * @param name giá trị thực của flag.
       * @param shortName tên ngắn của flag.
       */
      void addFlagDefinition(
        const std::string& name,
        const std::string& shortName,
        const std::string& description = ""
      );

      /**
       * @brief Thêm một flag mới vào trong danh sách.
       */
      void addFlag(const TuargFlag& tuargFlag);

      /**
       * @brief Lấy giá trị thực của command.
       */
      std::string getValueCopy() const;

      /**
       * @brief Lấy tham chiếu của danh sách các options
       */
      const TuargOptionMap& getOptionMapConstRef() const;

      /**
       * @brief Lấy tham chiếu của danh sách các flags
       */
      const TuargFlagMap& getFlagMapConstRef() const;

      /**
       * @brief Thêm mô tả cho command
       */
      void setDescription(std::string description);

      /**
       * @brief Lấy mô tả của command.
       */
      std::string getDescriptionCopy();

      /**
       * @brief In mô tả và hướng dẫn sử dụng thông qua
       * các mô tả của flags và options (nếu có).
       */
      void printDescriptionAndManual() const;

    private:

      std::string _value;
      TuargOptionMap _optionMap = {};
      TuargFlagMap _flagMap = {};
      std::string _description;
      size_t _longestNameLength = 0;
      size_t _longestShortNameLength = 0;
  };

}

#endif