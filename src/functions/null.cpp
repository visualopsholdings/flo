/*
  null.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/null.hpp"

#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

optional<rfl::Generic> Null::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}

  // just pass it through.
  return state->getElem();
  
}

shared_ptr<Function> Null::create() {

  return shared_ptr<Function>(new Null());
  
}
