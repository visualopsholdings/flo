/*
  select.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 31-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_select
#define H_select

#include "../function.hpp"

class Select: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure);

  static fPtr create();
  
};

#endif // H_select
