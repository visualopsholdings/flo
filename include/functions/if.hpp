/*
  if.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_if
#define H_if

#include "../function.hpp"

class If: public Function
{
public:
  
  // Function
  virtual optional<json> exec(const Transform &transform, State *state, json &closure);

  static fPtr create();
  
};

#endif // H_if
