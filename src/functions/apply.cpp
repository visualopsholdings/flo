/*
  apply.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 14-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions/apply.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

optional<rfl::Generic> Apply::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
  State localState(*state);
  
  return apply(transform, &localState, closure);
   
}

optional<rfl::Generic> Apply::apply(Transform &transform, State *state, rfl::Generic &closure) {

  auto v = Generic::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not vector";
    return nullopt;
  }
  
  int arity = state->hasColl() ? (!state->hasElem() ? 0 : 1) : 2;

  for (auto b: *v) {
    auto val = transform.exec(b, state);
    if (val) {
//      BOOST_LOG_TRIVIAL(trace) << Generic::toString(*val);
      auto v2 = Generic::getVector(*val);
      if (v2) {
        BOOST_LOG_TRIVIAL(trace) << "found vector (2)";
        state->setColl(*v2);
        state->clearElem();
        arity = 2;
      }
      else {
        BOOST_LOG_TRIVIAL(trace) << "found elem (1)";
        state->setElem(*val);
        state->clearColl();
        arity = 1;
      }
    }
  }
  BOOST_LOG_TRIVIAL(trace) << "arity " << arity;
  
  switch (arity) {
    case 2:
      if (state->hasColl()) {
        return state->getColl();
      }
      break;
    case 1:
      if (state->hasElem()) {
        return state->getElem();
      }
      break;
  }
  
  return nullopt;

}

shared_ptr<Function> Apply::create() {

  return shared_ptr<Function>(new Apply());
  
}
