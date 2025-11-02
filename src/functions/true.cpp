/*
  true.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "values.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

template<>
optional<rfl::Generic> Func<True>::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "true " << Generic::toString(closure);

  return true;
  
}
