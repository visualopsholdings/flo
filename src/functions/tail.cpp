/*
  tail.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions/tail.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"
#include "functions/apply.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

optional<rfl::Generic> Tail::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "Tail exec " << Generic::toString(closure);
  
  if (!state->hasColl()) {
    BOOST_LOG_TRIVIAL(error) << "Map expects a data as a list";
    return nullopt;
  }
  auto data = state->getColl();
  if (data.size() == 0) {
    return nullopt;
  }
  vector<rfl::Generic> tail;
  copy(data.begin()+1, data.end(), back_inserter(tail));
//  cout << Generic::toString(tail) << endl;
  return tail;
  
}

shared_ptr<Function> Tail::create() {

  return shared_ptr<Function>(new Tail());
  
}
