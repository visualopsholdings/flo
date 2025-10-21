/*
  string.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions/string.hpp"

#include "transform.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

optional<rfl::Generic> String::exec(Transform &transform, State *state, rfl::Generic &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "string " << Generic::toString(closure);

  auto s = Generic::getString(closure);
  if (!s) {
    BOOST_LOG_TRIVIAL(error) << "closure is not string";
    return nullopt;
  }
  
  return *s;
  
}

shared_ptr<Function> String::create() {

  return shared_ptr<Function>(new String());
  
}
