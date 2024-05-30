/*
  equal.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/equal.hpp"

#include "transform.hpp"

optional<json> Equal::exec(const Transform &transform, State *state, json &closure) {

  return transform.error("equal not implemented");
    
}

shared_ptr<Function> Equal::create() {

  return shared_ptr<Function>(new Equal());
  
}
