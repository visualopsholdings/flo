/*
  math.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 23-Sep-2026
  
  "Math" category functions as specified in docs.json.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_math
#define H_math

#include "function.hpp"

namespace vops {
namespace flo {

class Integer: public Func<Integer> {
};

class Number: public Func<Number> {
};

class Add: public Func<Add> {
};

class Subtract: public Func<Subtract> {
};

class Multiply: public Func<Multiply> {
};

class Divide: public Func<Divide> {
};

double evalDouble(Transform &transform, State *state, const DictG &e);
  // evaulate an arg as a double.
  
} // flo
} // vops

#endif // H_math
