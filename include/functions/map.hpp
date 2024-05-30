/*
  map.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_map
#define H_map

#include "../function.hpp"

class Map: public Function
{
public:
  Map();
  
  // Function
  virtual json exec(const Transform &transform, State *state, const json &closure);

  static fPtr create();
  
private:

//  optional<json> apply(const Transform &transform, State *state, const json &closure);
  
};

#endif // H_map
