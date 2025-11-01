/*
  map.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions/map.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"
#include "functions/apply.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

optional<rfl::Generic> Map::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "Map exec " << Generic::toString(closure);
  
  auto body = Generic::getVector(closure);
  if (!body) {
    BOOST_LOG_TRIVIAL(error) << "Map expects a list";
    return nullopt;
  }
  if (!state->hasColl()) {
    BOOST_LOG_TRIVIAL(error) << "Map expects a data as a list";
    return nullopt;
  }
  auto data = state->getColl();
  vector<rfl::Generic> mapped;
  std::transform(data.begin(), data.end(), back_inserter(mapped), [&transform, state, body](auto e) {
    State localState;
    localState.set(e);
    auto a = Apply::apply(transform, &localState, *body);
    if (a) {
      return *a;
    }
    rfl::Generic empty;
    return empty;
  });
  return mapped;
  
}

shared_ptr<Function> Map::create() {

  return shared_ptr<Function>(new Map());
  
}
