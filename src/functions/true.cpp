/*
  true.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/true.hpp"

#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> True::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
  BOOST_LOG_TRIVIAL(trace) << "true " << *Reflect::getString(closure);

  return true;
  
}

shared_ptr<Function> True::create() {

  return shared_ptr<Function>(new True());
  
}
