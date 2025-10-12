/*
  getmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/getmember.hpp"

#include "transform.hpp"
#include "state.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> GetMember::exec(Transform &transform, State *state, rfl::Generic &closure) {

  BOOST_LOG_TRIVIAL(trace) << "getmember " << *Reflect::getString(closure);

  auto obj = Reflect::getObject(closure);
  if (!obj) {
    BOOST_LOG_TRIVIAL(error) << "closure not object";
    return nullopt;
  }
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}
	
  auto name = Reflect::getString(*obj, "name");
  if (!name) {
    BOOST_LOG_TRIVIAL(error) << "missing name";
    return nullopt;
  }
	auto elem = state->getElem();
	return elem[*name];
    
}

shared_ptr<Function> GetMember::create() {

  return shared_ptr<Function>(new GetMember());
  
}
