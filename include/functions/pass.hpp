/*
  pass.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 15-Oct-2025
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_pass
#define H_pass

#include "../function.hpp"

namespace flo {

class Pass: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_pass
