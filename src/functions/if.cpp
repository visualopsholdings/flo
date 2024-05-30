/*
  if.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/if.hpp"

#include "transform.hpp"

#include <boost/log/trivial.hpp>

optional<json> If::exec(Transform &transform, State *state, json &closure) {
  
  BOOST_LOG_TRIVIAL(trace) << "if " << closure;

  if (!closure.is_object()) {
    BOOST_LOG_TRIVIAL(trace) << "closure not object";
    return nullopt;
  }
  if (!closure.as_object().if_contains("p")) {
    BOOST_LOG_TRIVIAL(error) << "no p";
    return nullopt;
  }
  auto p = closure.as_object()["p"];
  if (!p.is_object()) {
    BOOST_LOG_TRIVIAL(error) << "p not object";
    return nullopt;
  }
  auto result = transform.exec(p, state);
  if (result && result->is_bool() && result->as_bool()) {
    auto then = closure.as_object()["then"];
    if (!then.is_object()) {
      BOOST_LOG_TRIVIAL(error) << "then not object";
      return nullopt;
    }
    return transform.exec(then, state);
  }
  
  return nullopt;
  
}

shared_ptr<Function> If::create() {

  return shared_ptr<Function>(new If());
  
}
