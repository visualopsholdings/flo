/*
  equal.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_equal
#define H_equal

#include "../function.hpp"

namespace flo {

class Equal: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_equal
