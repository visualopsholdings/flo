/*
  transform.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "transform.hpp"

Transform::Transform(json &json) : _json(json) {
}

optional<json> Transform::get_value(State *state, json closure) const {

  if (closure.is_object()) {
    return exec(closure, state);
  }
  
  return closure;
}

optional<json> Transform::exec(json closure, State *state) const {

  if (closure.is_object()) {
    if (closure.as_object().size() == 0) {
      return nullopt; // treat like a terminal.
    }
    auto method = get_method(closure, state);
  }
  return nullopt;
  
}

Method Transform::get_method(json closure, State *state) const {
  
  return Method(0, closure);
  
  
}
