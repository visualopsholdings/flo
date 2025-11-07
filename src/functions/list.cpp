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
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;

template<>
optional<DictG> Func<List>::exec(Transform &transform, State *state, const DictG &closure) {
  
  using vops::Dict;

  auto v = Dict::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not a list";
    return nullopt;
  }
  
//  BOOST_LOG_TRIVIAL(trace) << "list found vector " << Dict::toString(*v);
  vector<DictG> newv;
  std::transform(v->begin(), v->end(), back_inserter(newv), [state, &transform](auto e) {
    auto val = transform.exec(e, state);
    if (val) {
//      BOOST_LOG_TRIVIAL(trace) << "list val " << Dict::toString(*val);
      return *val;
    }
    return DictG();
  });
//  BOOST_LOG_TRIVIAL(trace) << "list vector " << Dict::toString(newv);
  return newv;
     
}
