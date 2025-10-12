/*
  string.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_string
#define H_string

#include "../function.hpp"

class String: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure);

  static fPtr create();
  
};

#endif // H_string
