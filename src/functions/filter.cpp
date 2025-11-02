/*
  filter.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "list.hpp"
#include "generic.hpp"
#include "state.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>
#include <ranges>

using namespace std;
using namespace flo;

template<>
optional<rfl::Generic> Func<Filter>::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "Filter exec " << Generic::toString(closure);
  
  auto p = Generic::getObject(Generic::getObject(closure), "p");
  if (!p) {
    BOOST_LOG_TRIVIAL(error) << "Filter expects a predicate";
    return nullopt;
  }
  if (!state->hasColl()) {
    BOOST_LOG_TRIVIAL(error) << "Filter expects a data as a list";
    return nullopt;
  }
  auto data = state->getColl();
  
  vector<rfl::Generic> filtered;
  copy_if(data.begin(), data.end(), back_inserter(filtered), [&transform, state, p](auto e) {
    State localState;
    localState.set(e);
    auto result = transform.exec(*p, &localState);
    if (result) {
      auto b = Generic::getBool(*result);
      return b && *b;
    }
    return false;
  });
  return filtered;
  
}
