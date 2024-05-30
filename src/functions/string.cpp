/*
  string.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/string.hpp"

#include "transform.hpp"

#include <boost/log/trivial.hpp>

optional<json> String::exec(Transform &transform, State *state, json &closure) {

  BOOST_LOG_TRIVIAL(trace) << "string " << closure;

  return closure;
    
}

shared_ptr<Function> String::create() {

  return shared_ptr<Function>(new String());
  
}
