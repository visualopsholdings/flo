/*
  setmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/setmember.hpp"

#include "transform.hpp"

#include <boost/log/trivial.hpp>

optional<json> SetMember::exec(Transform &transform, State *state, json &closure) {

  BOOST_LOG_TRIVIAL(trace) << "setmember " << closure;

  if (!closure.is_object()) {
    BOOST_LOG_TRIVIAL(error) << "closure not object";
    return nullopt;
  }
	if (!transform.getJson().is_object()) {
    BOOST_LOG_TRIVIAL(error) << "json not object";
    return nullopt;
	}
  auto obj = closure.as_object();
  if (!obj.if_contains("name")) {
    BOOST_LOG_TRIVIAL(error) << "missing name";
    return nullopt;
  }
	string name = boost::json::value_to<string>(obj["name"]);
  if (!obj.if_contains("value")) {
    BOOST_LOG_TRIVIAL(error) << "missing value";
    return nullopt;
  }
	auto value = obj["value"];
	
  return transform.error("setmember not implemented");
    
}

shared_ptr<Function> SetMember::create() {

  return shared_ptr<Function>(new SetMember());
  
}
