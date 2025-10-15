/*
  cur.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 15-Oct-2025
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_cur
#define H_cur

#include "../function.hpp"

namespace flo {

class Cur: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_cur
