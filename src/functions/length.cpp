/*
  length.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "list.hpp"
#include "dict.hpp"
#include "state.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

template<>
optional<DictG> Func<Length>::exec(Transform &transform, State *state, const DictG &closure) {
  
  using vops::Dict;

  BOOST_LOG_TRIVIAL(trace) << "Length exec " << Dict::toString(closure);
  
  if (state->hasColl()) {
    return (long long)state->getColl().size();
  }
  if (state->hasElem()) {
    auto g = state->getElem();
    auto s = Dict::getString(g);
    if (s) {
//      cout << *s << endl;
      return (long long)s->size();
    }
    auto o = Dict::getObject(g);
    if (o) {
      return  (long long)o->size();
    }
  }
  
  return nullopt;
  
}
