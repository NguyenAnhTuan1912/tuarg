#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <unordered_map>
#include <vector>

namespace Tuarg {

typedef bool TuargParserOption;
typedef std::unordered_map<std::string, TuargParserOption> TuargParserOptions;

/**
 * @class ArgParser
 * @brief Class để xử lý parsing các đối số dòng lệnh.
 * 
 * Lớp này cung cấp chức năng thêm các option và kiểm tra xem
 * option nào có được truyền vào khi chạy chương trình.
 */
class TuargParser {
  public:
    /**
     * @brief Kiểm tra xem một option nào đó có tồn tại trong parser
     * 
     * @param name tên của option
     * @return void
     */
    void parse(int argc, char* argv[]);

    /**
     * @brief Thêm một option mới vào trong map
     * 
     * @param name tên của option
     * @return void
     */
    void addOption(const std::string& name);

    /**
     * @brief Kiểm tra xem một option nào đó có tồn tại trong parser
     * hay không?
     * 
     * @param name tên của option
     * @return nếu như có thì là `true` còn không thì `false`
     */
    bool hasOption(const std::string& name) const;

    const TuargParserOptions& getOptions() const;

  private:
    TuargParserOptions options_;
};

}

#endif