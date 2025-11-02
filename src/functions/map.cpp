/*
  map.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "list.hpp"
#include "control.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

template<>
optional<rfl::Generic> Func<Map>::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
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
  auto apply = bind(&Apply::create)();
  auto data = state->getColl();
  vector<rfl::Generic> mapped;
  std::transform(data.begin(), data.end(), back_inserter(mapped), [&transform, state, body, apply](auto e) {
    State localState;
    localState.set(e);
    auto a = apply->exec(transform, &localState, *body);
    if (a) {
      return *a;
    }
    rfl::Generic empty;
    return empty;
  });
  return mapped;
  
}
