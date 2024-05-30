/*
  null.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/null.hpp"

#include "transform.hpp"

optional<json> Null::exec(const Transform &transform, State *state, json &closure) {
  
  // just pass it through.
  return transform.getJson();
  
}

shared_ptr<Function> Null::create() {

  return shared_ptr<Function>(new Null());
  
}
