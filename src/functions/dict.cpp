/*
  dict.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/dict.hpp"

Dict::Dict() {

}

json Dict::exec(const Transform &transform, State *state, const json &closure) {
  
  return { { "message", "dict not implemented" } };
  
  
}

shared_ptr<Function> Dict::create() {

  return shared_ptr<Function>(new Dict());
  
}
