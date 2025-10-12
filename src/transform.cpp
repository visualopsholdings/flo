/*
  transform.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "transform.hpp"

#include "functions.hpp"
#include "reflect.hpp"

#include <boost/log/trivial.hpp>
#include <rfl/json.hpp>

Transform::Transform(Functions &functions) : _functions(functions) {
}

optional<rfl::Generic> Transform::exec(rfl::Generic &closure, State *state) {

  BOOST_LOG_TRIVIAL(trace) << "exec " << *Reflect::getString(closure);

  auto obj = Reflect::getObject(closure);
  if (obj) {
    if (obj->size() == 0) {
      BOOST_LOG_TRIVIAL(trace) << "empty closure is terminal";
      return nullopt; // treat like a terminal.
    }
    
    // get first nvp in closure
    auto first = obj->begin();
    
    string name = get<0>(*first);
    BOOST_LOG_TRIVIAL(trace) << "first " << name;
    
    if (!_functions.has(name)) {
      return error("function " + name + " not found");
    }
    
    // get function representing name.
    auto f = _functions.get(name);
    
    // call down with the closure.
    return f->exec(*this, state, get<1>(*first));
    
  }
  return nullopt;
  
}

rfl::Generic Transform::error(const string &msg) const {

  BOOST_LOG_TRIVIAL(error) << msg;
  return *rfl::json::read<rfl::Generic>("{\"error\":\"" + msg + "\"}");
  
}
