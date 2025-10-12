/*
  select.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 31-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/select.hpp"

#include "transform.hpp"
#include "state.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> Select::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
  BOOST_LOG_TRIVIAL(trace) << "select " << *Reflect::getString(closure);

  auto a = Reflect::getVector(closure);
  if (!a) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
  // select the first function that returns something.
	for (auto i: *a) {
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
