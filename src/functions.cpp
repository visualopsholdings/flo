/*
  functions.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions.hpp"

#include "functions/null.hpp"
#include "functions/map.hpp"

Functions::Functions() {

  _functions["null"] = bind(&Null::create);
  _functions["map"] = bind(&Map::create);
  
}

fPtr Functions::get(const string &name) {
  return _functions[name]();
}
