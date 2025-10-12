/*
  equal.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/equal.hpp"

#include "transform.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> Equal::exec(Transform &transform, State *state, rfl::Generic &closure) {

  BOOST_LOG_TRIVIAL(trace) << "exec " << *Reflect::getString(closure);

  auto a = Reflect::getVector(closure);
  if (!a) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
	auto i = a->begin();
	auto head = *i;
	auto lvalue = transform.exec(head, state);
	i++;
	while (i != a->end()) {
		auto rvalue = transform.exec(*i, state);
		if (!lvalue || !rvalue || (Reflect::getString(*lvalue) != Reflect::getString(*rvalue))) {
			return false;
		}
		i++;
	}
  return true;
    
}

shared_ptr<Function> Equal::create() {

  return shared_ptr<Function>(new Equal());
  
}
