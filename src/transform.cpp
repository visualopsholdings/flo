/*
  transform.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "transform.hpp"

#include "functions.hpp"

#include <boost/log/trivial.hpp>

Transform::Transform(json &json, Functions &functions) : _json(json), _functions(functions) {
}

json &Transform::getJson() const {
  return _json;
}

optional<json> Transform::exec(json &closure, State *state) const {

  BOOST_LOG_TRIVIAL(trace) << "exec " << closure;

  if (closure.is_object()) {
    if (closure.as_object().size() == 0) {
      BOOST_LOG_TRIVIAL(trace) << "empty closure is terminal";
      return nullopt; // treat like a terminal.
    }
    auto first = closure.as_object().begin();
    BOOST_LOG_TRIVIAL(trace) << "first " << (*first).key();
    auto f = _functions.get((*first).key());
    return f->exec(*this, state, (*first).value());
    
  }
  return nullopt;
  
}
