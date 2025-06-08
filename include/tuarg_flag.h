#ifndef TUARG_FLAG_H
#define TUARG_FLAG_H

#include "tuarg_types.h"

namespace Tuarg {
  class TuargFlag;
  using TuargFlagMap = std::unordered_map<std::string, std::shared_ptr<TuargFlag>>;

  /**
   * @class TuargFlag
   * @brief Class dùng để quản lý các option.
   * 
   * Khi thêm một option mới, thì mình có thể có nhiều lựa chọn
   * để định nghĩa option đó.
   */
  class TuargFlag {
    public:

      TuargFlag();
      TuargFlag(const std::string& name);
      TuargFlag(const std::string& name, const std::string& shortName);
      TuargFlag(const std::string& name, const std::string& shortName, const std::string& description);

      /**
       * @brief Lấy giá trị thực, chính thức của option.
       */
      std::string getName() const;

      /**
       * @brief lấy short name của flag.
       */
      std::string getShortName() const;

      /**
       * @brief Thêm mô tả cho flag.
       */
      void setDescription(std::string description);

      /**
       * @brief Lấy mô tả của flag.
       */
      std::string getDescriptionCopy();

    private:

      std::string _name;
      std::string _shortName;
      std::string _description;
  };

}

#endif