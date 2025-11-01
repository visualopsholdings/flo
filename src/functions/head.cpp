/*
  head.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions/head.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"
#include "functions/apply.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

optional<rfl::Generic> Head::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "Head exec " << Generic::toString(closure);
  
  if (!state->hasColl()) {
    BOOST_LOG_TRIVIAL(error) << "Map expects a data as a list";
    return nullopt;
  }
  auto data = state->getColl();
  if (data.size() == 0) {
    return nullopt;
  }

  return *(data.begin());
  
}

shared_ptr<Function> Head::create() {

  return shared_ptr<Function>(new Head());
  
}
