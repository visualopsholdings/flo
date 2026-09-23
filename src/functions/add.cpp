/*
  add.cpp
  
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
optional<DictG> Func<Add>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "subtract " << Dict::toString(closure);

  auto v = Dict::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not a list";
    return nullopt;
  }
  double acc = 0;
  for (auto n: *v) {
    acc += evalDouble(transform, state, n);
  }
  
  return acc;
       
}
