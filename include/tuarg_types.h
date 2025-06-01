#ifndef TUARG_TYPES_H
#define TUARG_TYPES_H

#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

namespace Tuarg {

  enum class EPositionalArg {
    Required,
    Optional,
    Variadic
  };
  typedef std::string TuargArg;

}

#endif