/*
  integer.cpp
  
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
optional<DictG> Func<Integer>::exec(Transform &transform, State *state, const DictG &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "integer " << Dict::toString(closure);

  auto s = Dict::getNum(closure);
  if (!s) {
    BOOST_LOG_TRIVIAL(error) << "closure is not number";
    return nullopt;
  }
  
  return *s;
  
}
