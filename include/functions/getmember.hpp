/*
  getmember.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_getmember
#define H_getmember

#include "../function.hpp"

class GetMember: public Function
{
public:
  
  // Function
  virtual optional<json> exec(Transform &transform, State *state, json &closure);

  static fPtr create();
  
};

#endif // H_getmember
