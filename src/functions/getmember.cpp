/*
  getmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/getmember.hpp"

#include "transform.hpp"

optional<json> GetMember::exec(const Transform &transform, State *state, json &closure) {


  return transform.error("getmember not implemented");
    
}

shared_ptr<Function> GetMember::create() {

  return shared_ptr<Function>(new GetMember());
  
}
