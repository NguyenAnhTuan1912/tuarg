#ifndef TUARG_OPTION_H
#define TUARG_OPTION_H

#include "tuarg_types.h"

namespace Tuarg {
  class TuargOption;
  using TuargOptionMap = std::unordered_map<std::string, std::shared_ptr<TuargOption>>;

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
      TuargOption(const std::string& name);
      TuargOption(const std::string& name, Tuarg::EPositionalArg positionalType);
      TuargOption(
        const std::string& name,
        const std::string& shortName,
        Tuarg::EPositionalArg positionalType
      );
      TuargOption(
        const std::string& name,
        const std::string& shortName,
        Tuarg::EPositionalArg positionalType,
        const std::string& description
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
      std::string getName() const;

      /**
       * @brief Lấy tên ngắn của option.
       */
      std::string getShortName() const;

      /**
       * @brief Lấy kiểu positional argument của option.
       */
      Tuarg::EPositionalArg getPositionalType() const;

      /**
       * @brief Thêm mô tả cho option.
       */
      void setDescription(std::string description);

      /**
       * @brief Lấy mô tả của option.
       */
      std::string getDescriptionCopy();

    private:

      std::string _name;
      std::string _shortName;
      Tuarg::EPositionalArg positionalType_ = Tuarg::EPositionalArg::OnlyOne;
      std::string _description;
  };

}

#endif