/*
  setmember.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_setmember
#define H_setmember

#include "../function.hpp"

class SetMember: public Function
{
public:
  
  // Function
  virtual optional<json> exec(const Transform &transform, State *state, json &closure);

  static fPtr create();
  
};

#endif // H_setmember
