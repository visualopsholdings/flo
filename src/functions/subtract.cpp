/*
  subtract.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 23-Sep-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "math.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace vops::flo;

template<>
optional<DictG> Func<Subtract>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "subtract " << Dict::toString(closure);

  auto v = Dict::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not a list";
    return nullopt;
  }
  if (v->size() != 2) {
    BOOST_LOG_TRIVIAL(error) << "list doesn't have 2 elements";
    return nullopt;
  }
  auto a1 = evalDouble(transform, state, (*v)[0]);
  auto a2 = evalDouble(transform, state, (*v)[1]);
  
  return a1 - a2;
       
}
