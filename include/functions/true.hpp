/*
  true.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_true
#define H_true

#include "../function.hpp"

class True: public Function
{
public:
  
  // Function
  virtual optional<json> exec(Transform &transform, State *state, json &closure);

  static fPtr create();
  
};

#endif // H_true
