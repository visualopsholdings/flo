/*
  string.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/string.hpp"

#include "transform.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> String::exec(Transform &transform, State *state, rfl::Generic &closure) {

  BOOST_LOG_TRIVIAL(trace) << "string " << *Reflect::getString(closure);

  return closure;
    
}

shared_ptr<Function> String::create() {

  return shared_ptr<Function>(new String());
  
}
