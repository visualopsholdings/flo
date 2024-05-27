/*
  method.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "method.hpp"

Method::Method(fPtr func, json closure): _func(func), _closure(closure) {
}

json Method::call(const Transform &transform, State *state, json closure) {

  return {};
  
}
