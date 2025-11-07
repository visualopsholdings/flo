/*
  map.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "listfun.hpp"
#include "control.hpp"
#include "dict.hpp"
#include "state.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace vops::flo;

template<>
optional<DictG> Func<Map>::exec(Transform &transform, State *state, const DictG &closure) {
  
  using vops::Dict;

//  BOOST_LOG_TRIVIAL(trace) << "Map exec " << Dict::toString(closure);
  
  auto body = Dict::getVector(closure);
  if (!body) {
    BOOST_LOG_TRIVIAL(error) << "Map expects a list";
    return nullopt;
  }
  if (!state->hasColl()) {
    BOOST_LOG_TRIVIAL(error) << "Map expects a data as a list";
    return nullopt;
  }
  
  auto data = state->getColl();
  
  // don't do anything if map has nothing to apply. Just return the orignal data.
  if (body->size() == 0) {
    return data;
  }
  
  auto apply = bind(&Apply::create)();
  vector<DictG> mapped;
  std::transform(data.begin(), data.end(), back_inserter(mapped), [&transform, state, body, apply](auto e) {
    State localState;
    localState.set(e);
    auto a = apply->exec(transform, &localState, *body);
    if (a) {
      return *a;
    }
    DictG empty;
    return empty;
  });
  return mapped;
  
}
