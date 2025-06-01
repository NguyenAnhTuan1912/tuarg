#ifndef TUARG_OPTION_H
#define TUARG_OPTION_H

#include "tuarg_types.h"

namespace Tuarg {
  class TuargOption;
  typedef std::unordered_map<std::string, std::shared_ptr<TuargOption>> TuargOptionMap;

  /**
   * @class TuargOption
   * @brief Class dùng để quản lý các option.
   * 
   * Khi thêm một option mới, thì mình có thể có nhiều lựa chọn
   * để định nghĩa option đó.
   */
  class TuargOption {
    public:

      TuargOption();
      TuargOption(const std::string& value);
      TuargOption(const std::string& value, Tuarg::EPositionalArg positionalType);
      TuargOption(
        const std::string& value,
        const std::string& shortName,
        Tuarg::EPositionalArg positionalType
      );

      /**
       * @brief Gán giá trị mới cho positional type của option.
       * 
       * @param positionalType kiểu của positional argument
       */
      void setPositionalArgType(Tuarg::EPositionalArg positionalType);

      /**
       * @brief Gán một danh sách tham số mới cho option.
       * 
       * @param args danh sách tham số mới
       */
      void setArgs(const std::vector<std::string>& args);
      
      /**
       * @brief Thêm một tham số mới vào trong danh sách.
       * 
       * @param arg tham số cần được thêm.
       */
      void addArg(const std::string& arg);

      /**
       * @brief Lấy giá trị thực, chính thức của option.
       */
      std::string getValue() const;

      /**
       * @brief Lấy tên ngắn của option.
       */
      std::string getShortName() const;

      /**
       * @brief Lấy kiểu positional argument của option.
       */
      Tuarg::EPositionalArg getPositionalType() const;

      /**
       * @brief Lấy tham  chiếu của danh sách tham số.
       */
      const std::vector<std::string>& getArgs() const;

    private:

      std::string value_;
      std::string shortName_;
      std::vector<std::string> args_;
      Tuarg::EPositionalArg positionalType_ = Tuarg::EPositionalArg::Optional;
  };

}

#endif