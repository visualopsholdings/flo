/*
  dict.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_dict
#define H_dict

#include "../function.hpp"

class Dict: public Function
{
public:
  Dict();
  
  // Function
  virtual json exec(const Transform &transform, State *state, const json &closure);

  static fPtr create();
  
};

#endif // H_dict
