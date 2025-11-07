/*
  true.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "values.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;

template<>
optional<DictG> Func<True>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "true " << Dict::toString(closure);

  return true;
  
}
