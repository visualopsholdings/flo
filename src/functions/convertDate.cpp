/*
  convertDate.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 24-Sep-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "datefun.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"
#include "date.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace vops::flo;

template<>
optional<DictG> Func<ConvertDate>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "convertDate " << Dict::toString(closure);

  auto value = transform.exec(closure, state);
  if (!value) {
    return 0;
  }
  auto s = Dict::getString(*value);
  if (s) {
    return Date(true).fromISODate(*s);
  }
  auto n = Dict::getNum(*value);
  if (n) {
    // we need to work out if this is actually a valid date. For now just let them pass through.
    return *n;
  }

  BOOST_LOG_TRIVIAL(error) << "don't handle the type for a date.";
  return nullopt;
         
}
