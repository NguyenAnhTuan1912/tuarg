#ifndef TUARG_UTILS_H
#define TUARG_UTILS_H

#include <iostream>

#include "tuarg_types.h"

namespace Tuarg {
  namespace Utils {
    /**
     * @brief In ra kết quả sau khi phân tích xong chuỗi đối số.
     * 
     * @param result kết quả trả về từ parser.parse()
     */
    void printTuargParseResult(const TuargParseResult& result);
  };
};

#endif