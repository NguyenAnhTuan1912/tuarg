#ifndef TUARG_UTILS_H
#define TUARG_UTILS_H

#include <iostream>
#include <algorithm> 
#include <cctype>
#include <locale>

#include "tuarg_types.h"

namespace Tuarg {
  namespace Utils {
    /**
     * @brief In ra kết quả sau khi phân tích xong chuỗi đối số.
     * 
     * @param result kết quả trả về từ parser.parse()
     */
    void printTuargParseResult(const TuargParseResult& result);

    /**
     * @brief Loại bỏ khoảng trắng ở đầu chuỗi.
     * 
     * @param str chuỗi cần loại bỏ
     */
    void ltrim(std::string& str);

    /**
     * @brief Loại bỏ khoảng trắng ở cuối chuỗi.
     * 
     * @param str chuỗi cần loại bỏ
     */
    void rtrim(std::string& str);

    /**
     * @brief Loại bỏ khoảng trắng ở đầu và cuối chuỗi.
     * 
     * @param str chuỗi cần loại bỏ
     */
    void trim(std::string& str);
  };
};

#endif