/*
  setmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/setmember.hpp"

#include "transform.hpp"

optional<json> SetMember::exec(const Transform &transform, State *state, json &closure) {


  return transform.error("setmember not implemented");
    
}

shared_ptr<Function> SetMember::create() {

  return shared_ptr<Function>(new SetMember());
  
}
