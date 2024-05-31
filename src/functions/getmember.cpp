/*
  getmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/getmember.hpp"

#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

optional<json> GetMember::exec(Transform &transform, State *state, json &closure) {

  BOOST_LOG_TRIVIAL(trace) << "getmember " << closure;

  if (!closure.is_object()) {
    BOOST_LOG_TRIVIAL(error) << "closure not object";
    return nullopt;
  }
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}
	
  auto obj = closure.as_object();
  if (!obj.if_contains("name")) {
    BOOST_LOG_TRIVIAL(error) << "missing name";
    return nullopt;
  }
	auto elem = state->getElem();
	string name = boost::json::value_to<string>(obj["name"]);
	return elem[name];
    
}

shared_ptr<Function> GetMember::create() {

  return shared_ptr<Function>(new GetMember());
  
}
