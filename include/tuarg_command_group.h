#ifndef TUARG_COMMAND_GROUP_H
#define TUARG_COMMAND_GROUP_H

#include "tuarg_types.h"
#include "tuarg_option.h"
#include "tuarg_command.h"

namespace Tuarg {
  class TuargCommandGroup {
    public:
      TuargCommandGroup();

      /**
       * @brief Thêm một root command mới bằng cách truyền tham chiếu
       * của một command đã có sẵn.
       * 
       * @param tuargCommand tham chiếu của command gốc. 
       */
      void addRootCommand(TuargCommand& command);

      /**
       * @brief Thêm một root command mới bằng cách truyền tham chiếu
       * của một command đã có sẵn.
       * 
       * @param command tên của command gốc.
       * @param flags danh sách các tham chiếu của flags. 
       * @param options danh sách các tham chiếu của options.
       */
      void addRootCommandDefinition(
        const std::string& command,
        const std::vector<TuargFlag>& flags,
        const std::vector<TuargOption>& options
      );

      /**
       * @brief Thêm một command mới bằng cách truyền tham chiếu
       * của một command đã có sẵn.
       * 
       * @param command tham chiếu của command. 
       */
      void addCommand(TuargCommand& tuargCommand);

      /**
       * @brief Thêm một command mới bằng cách truyền tham chiếu
       * của một command đã có sẵn.
       * 
       * @param command tên của command.
       * @param flags danh sách các tham chiếu của flags. 
       * @param options danh sách các tham chiếu của options.
       */
      void addCommandDefinition(
        const std::string& command,
        const std::vector<TuargFlag>& flags,
        const std::vector<TuargOption>& options
      );

      /**
       * @brief Lấy tham chiếu hằng của command gốc.
       */
      const TuargCommand& getRootCommandConstRef() const;

      /**
       * @brief Lấy tham chiếu hằng của command map.
       */
      const TuargCommandMap& getCommandMapConstRef() const;

    private:
      TuargCommand _rootCommand;
      TuargCommandMap _commandMap;
  };
}

#endif