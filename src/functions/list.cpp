/*
  list.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 25-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "list.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

template<>
optional<rfl::Generic> Func<List>::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
  auto v = Generic::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not a list";
    return nullopt;
  }
  
//  BOOST_LOG_TRIVIAL(trace) << "list found vector " << Generic::toString(*v);
  vector<rfl::Generic> newv;
  std::transform(v->begin(), v->end(), back_inserter(newv), [state, &transform](auto e) {
    auto val = transform.exec(e, state);
    if (val) {
//      BOOST_LOG_TRIVIAL(trace) << "list val " << Generic::toString(*val);
      return *val;
    }
    return rfl::Generic();
  });
//  BOOST_LOG_TRIVIAL(trace) << "list vector " << Generic::toString(newv);
  return newv;
     
}
