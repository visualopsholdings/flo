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

optional<rfl::Generic> Apply::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "Apply exec " << Generic::toString(closure);
  
  State localState(*state);
  
  auto res = apply(transform, &localState, closure);
  
//  BOOST_LOG_TRIVIAL(trace) << "Apply return " << Generic::toString(*res);

  return res;
  
}

optional<rfl::Generic> Apply::apply(Transform &transform, State *state, const rfl::Generic &closure) {

  auto v = Generic::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not vector";
    return nullopt;
  }
  
  int arity = state->hasColl() ? 2 : (state->hasElem() ? 1 : 0);
  BOOST_LOG_TRIVIAL(trace) << "apply arity in " << arity;

  for (auto b: *v) {
//    BOOST_LOG_TRIVIAL(trace) << "apply transforming " << Generic::toString(b);
    auto val = transform.exec(b, state);
    if (val) {
//      BOOST_LOG_TRIVIAL(trace) << "apply test val " << Generic::toString(*val);
      auto v2 = Generic::getVector(*val);
      if (v2) {
        BOOST_LOG_TRIVIAL(trace) << "apply found vector (2)";
        state->setColl(*v2);
        state->clearElem();
        arity = 2;
      }
      else {
        BOOST_LOG_TRIVIAL(trace) << "apply found elem (1)";
        state->setElem(*val);
        state->clearColl();
        arity = 1;
      }
    }
    else {
      BOOST_LOG_TRIVIAL(trace) << "apply found empty (1)";
      rfl::Generic empty;
      state->setElem(empty);
      state->clearColl();
      arity = 1;
    }
  }
  BOOST_LOG_TRIVIAL(trace) << "apply arity out " << arity;
  
  switch (arity) {
    case 2:
      return state->getColl();
    case 1:
      return state->getElem();
  }
  
  BOOST_LOG_TRIVIAL(trace) << "returning null?";

  return nullopt;

}

shared_ptr<Function> Apply::create() {

  return shared_ptr<Function>(new Apply());
  
}
