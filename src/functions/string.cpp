/*
  string.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "values.hpp"
#include "transform.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

template<>
optional<rfl::Generic> Func<String>::exec(Transform &transform, State *state, const rfl::Generic &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "string " << Generic::toString(closure);

  auto s = Generic::getString(closure);
  if (!s) {
    BOOST_LOG_TRIVIAL(error) << "closure is not string";
    return nullopt;
  }
  
  return *s;
  
}
