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
  
  // just pass it through.
  return closure;
  
}

shared_ptr<Function> If::create() {

  return shared_ptr<Function>(new If());
  
}
