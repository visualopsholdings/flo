/*
  cur.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 15-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "values.hpp"
#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;

template<>
optional<DictG> Func<Cur>::exec(Transform &transform, State *state, const DictG &closure) {
  
  if (state->hasElem()) {
    return state->getElem();
  }
  if (state->hasColl()) {
    return state->getColl();
  }

  return nullopt;
    
}
