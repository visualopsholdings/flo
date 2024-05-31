/*
  select.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 31-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/select.hpp"

#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

optional<json> Select::exec(Transform &transform, State *state, json &closure) {
  
  BOOST_LOG_TRIVIAL(trace) << "select " << closure;

  if (!closure.is_array()) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
  // select the first function that returns something.
	for (auto i: closure.as_array()) {
	  auto val = transform.exec(i, state);
	  if (val) {
	    return *val;
	  }
	}

  return nullopt;
    
}

shared_ptr<Function> Select::create() {

  return shared_ptr<Function>(new Select());
  
}
