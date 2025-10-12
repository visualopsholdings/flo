/*
  setmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/setmember.hpp"

#include "transform.hpp"
#include "state.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> SetMember::exec(Transform &transform, State *state, rfl::Generic &closure) {

  BOOST_LOG_TRIVIAL(trace) << "setmember " << *Reflect::getString(closure);

  auto obj = Reflect::getObject(closure);
  if (!obj) {
    BOOST_LOG_TRIVIAL(error) << "closure not object";
    return nullopt;
  }
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}

  auto name = Reflect::getString(obj, "name");
  if (!name) {
    BOOST_LOG_TRIVIAL(error) << "missing name";
    return nullopt;
  }
  auto v = Reflect::getGeneric(obj, "value");
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "missing value";
    return nullopt;
  }
	auto elem = state->getElem();
  auto value = transform.exec(*v, state);
  if (value) {
    elem[*name] = *value;
  }
  else {
    cerr << "not sure how to erase an element in Object" << endl;
  }
	
  return elem;
    
}

shared_ptr<Function> SetMember::create() {

  return shared_ptr<Function>(new SetMember());
  
}
