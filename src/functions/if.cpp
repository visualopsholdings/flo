/*
  if.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/if.hpp"

#include "transform.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>

optional<rfl::Generic> If::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
  BOOST_LOG_TRIVIAL(trace) << "if " << *Reflect::getString(closure);

  auto obj = Reflect::getObject(closure);
  if (!obj) {
    BOOST_LOG_TRIVIAL(trace) << "closure not object";
    return nullopt;
  }
  auto p = Reflect::getGeneric(obj, "p");
  if (!p) {
    BOOST_LOG_TRIVIAL(error) << "no p";
    return nullopt;
  }
  auto result = transform.exec(*p, state);
  if (!result) {
    return nullopt;
  }
  auto b = Reflect::getBool(*result);
  if (b && *b) {
    auto then = Reflect::getGeneric(obj, "then");
    if (!then) {
      BOOST_LOG_TRIVIAL(error) << "then not object";
      return nullopt;
    }
    return transform.exec(*then, state);
  }
  
  return nullopt;
  
}

shared_ptr<Function> If::create() {

  return shared_ptr<Function>(new If());
  
}
