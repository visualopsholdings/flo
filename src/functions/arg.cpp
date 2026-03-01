/*
  cur.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Mar-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "values.hpp"
#include "transform.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;

template<>
optional<DictG> Func<Arg>::exec(Transform &transform, State *state, const DictG &closure) {
  
  auto name = Dict::getString(closure);
  if (!name) {
    BOOST_LOG_TRIVIAL(error) << "closure not a name";
    return nullopt;
  }
  
  return state->getArg(*name);
    
}
