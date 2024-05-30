/*
  if.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/if.hpp"

If::If() {

}

json If::exec(const Transform &transform, State *state, const json &closure) {
  
  return { { "message", "if not implemented" } };
  
}

shared_ptr<Function> If::create() {

  return shared_ptr<Function>(new If());
  
}
