/*
  functions.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions.hpp"

#include "functions/null.hpp"
#include "functions/map.hpp"
#include "functions/if.hpp"
#include "functions/true.hpp"
#include "functions/dict.hpp"

Functions::Functions() {

  _functions["null"] = bind(&Null::create);
  _functions["map"] = bind(&Map::create);
  _functions["if"] = bind(&If::create);
  _functions["true"] = bind(&True::create);
  _functions["dict"] = bind(&Dict::create);
  
}

fPtr Functions::get(const string &name) {
  return _functions[name]();
}
