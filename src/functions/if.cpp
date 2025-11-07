/*
  if.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "transform.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;
using namespace vops;

template<>
optional<DictG> Func<If>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "if " << Dict::toString(closure);

  auto obj = Dict::getObject(closure);
  if (!obj) {
    BOOST_LOG_TRIVIAL(trace) << "closure not object";
    return nullopt;
  }
  auto p = Dict::getGeneric(obj, "p");
  if (!p) {
    BOOST_LOG_TRIVIAL(error) << "no p";
    return nullopt;
  }
  auto result = transform.exec(*p, state);
  if (!result) {
    return nullopt;
  }
  auto b = Dict::getBool(*result);
  if (b && *b) {
    auto then = Dict::getGeneric(obj, "then");
    if (!then) {
      BOOST_LOG_TRIVIAL(error) << "then not object";
      return nullopt;
    }
    return transform.exec(*then, state);
  }
  
  return nullopt;
  
}
