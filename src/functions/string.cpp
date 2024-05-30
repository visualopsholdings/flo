/*
  string.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/string.hpp"

#include "transform.hpp"

optional<json> String::exec(const Transform &transform, State *state, json &closure) {


  return transform.error("string not implemented");
    
}

shared_ptr<Function> String::create() {

  return shared_ptr<Function>(new String());
  
}
