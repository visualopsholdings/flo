/*
  quote.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 24-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;

template<>
optional<DictG> Func<Quote>::exec(Transform &transform, State *state, const DictG &closure) {
  
  // return the code wthout evaluating.
  return closure;
  
}
