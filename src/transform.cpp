/*
  transform.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "transform.hpp"

#include "functions.hpp"
#include "generic.hpp"
#include "functions/list.hpp"

#include <boost/log/trivial.hpp>
#include <rfl/json.hpp>

using namespace flo;

Transform::Transform(Functions &functions) : _functions(functions) {
}

optional<rfl::Generic> Transform::exec(const rfl::Generic &closure, State *state) {

//  BOOST_LOG_TRIVIAL(trace) << "exec " << Generic::toString(closure);

  auto obj = Generic::getObject(closure);
  if (obj) {
  
    BOOST_LOG_TRIVIAL(trace) << "exec found obj";
    
    if (obj->size() == 0) {
      BOOST_LOG_TRIVIAL(trace) << "empty closure is terminal";
      return nullopt; // treat like a terminal.
    }
    
    // get first nvp in closure
    auto first = obj->begin();
    
    string name = get<0>(*first);
    BOOST_LOG_TRIVIAL(trace) << name;
    
    if (_functions.hasNative(name)) {
    
      // get function representing name.
      auto f = _functions.getNative(name);
      
      // call down with the closure.
      return f->exec(*this, state, get<1>(*first));
      
    }
    else if (_functions.hasLibrary(name)) {

      // get transform representing name.
      auto t = _functions.getLibrary(name);
      
      // recursively call down
      return exec(t, state);
      
    }
    else {
      return error("function " + name + " not found");
    }
    
  }
  else {
    if (Generic::isVector(closure)) {
    
      // bind to lost and call.
      return bind(&List::create)()->exec(*this, state, closure);
    }
    return closure;
  }
  
  return nullopt;
  
}

rfl::Generic Transform::error(const string &msg) const {

  BOOST_LOG_TRIVIAL(error) << msg;
  rfl::Object<rfl::Generic> e;
  e["error"] = msg;
  return e;
  
}
