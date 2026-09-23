/*
  number.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 23-Sep-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "math.hpp"
#include "transform.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;
using namespace vops;

template<>
optional<DictG> Func<Number>::exec(Transform &transform, State *state, const DictG &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "number " << Dict::toString(closure);

  auto d = Dict::getDouble(closure);
  if (d) {
    return *d;
  }
  auto n = Dict::getNum(closure);
  if (n) {
    return *n;
  }
  
  BOOST_LOG_TRIVIAL(error) << "closure is not double or num";
  return nullopt;
  
}
