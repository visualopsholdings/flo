/*
  quote.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 24-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions/quote.hpp"

#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

optional<rfl::Generic> Quote::exec(Transform &transform, State *state, rfl::Generic &closure) {
  
  // return the code wthout evaluating.
  return closure;
  
}

shared_ptr<Function> Quote::create() {

  return shared_ptr<Function>(new Quote());
  
}
