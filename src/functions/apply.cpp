/*
  apply.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 14-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

template<>
optional<rfl::Generic> Func<Apply>::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "Apply exec " << Generic::toString(closure);
  
  State localState(*state);
  
  auto v = Generic::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not vector";
    return nullopt;
  }
  
  // don't do anything if apply has nothing to apply.
  if (v->size() == 0) {
    return nullopt;
  }
  
  int arity = localState.hasColl() ? 2 : (localState.hasElem() ? 1 : 0);
  BOOST_LOG_TRIVIAL(trace) << "apply arity in " << arity;

  for (auto b: *v) {
//    BOOST_LOG_TRIVIAL(trace) << "apply transforming " << Generic::toString(b);
    auto val = transform.exec(b, &localState);
    if (val) {
//      BOOST_LOG_TRIVIAL(trace) << "apply test val " << Generic::toString(*val);
      auto v2 = Generic::getVector(*val);
      if (v2) {
        BOOST_LOG_TRIVIAL(trace) << "apply found vector (2)";
        localState.setColl(*v2);
        localState.clearElem();
        arity = 2;
      }
      else {
        BOOST_LOG_TRIVIAL(trace) << "apply found elem (1)";
        localState.setElem(*val);
        localState.clearColl();
        arity = 1;
      }
    }
    else {
      BOOST_LOG_TRIVIAL(trace) << "apply found empty (1)";
      rfl::Generic empty;
      localState.setElem(empty);
      localState.clearColl();
      arity = 1;
    }
  }
  BOOST_LOG_TRIVIAL(trace) << "apply arity out " << arity;
  
  switch (arity) {
    case 2:
      return localState.getColl();
    case 1:
      return localState.getElem();
  }
  
  BOOST_LOG_TRIVIAL(trace) << "returning null?";

  return nullopt;
    
}
