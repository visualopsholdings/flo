/*
  string.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/string.hpp"

#include "transform.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

optional<rfl::Generic> String::exec(Transform &transform, State *state, rfl::Generic &closure) {

  BOOST_LOG_TRIVIAL(trace) << "string " << *Generic::getString(closure);

  return closure;
    
}

shared_ptr<Function> String::create() {

  return shared_ptr<Function>(new String());
  
}
