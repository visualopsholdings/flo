/*
  dict.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/dict.hpp"

optional<rfl::Generic> Dict::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
  // the closure is a dictionary.
  return closure;
  
}

shared_ptr<Function> Dict::create() {

  return shared_ptr<Function>(new Dict());
  
}
