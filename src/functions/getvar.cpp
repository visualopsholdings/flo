/*
  getvar.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 23-Sep-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "data.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;
using namespace vops;

template<>
optional<DictG> Func<GetVar>::exec(Transform &transform, State *state, const DictG &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "getvar " << Dict::toString(closure);

  auto name = Dict::getString(closure);
  if (!name) {
    BOOST_LOG_TRIVIAL(error) << "closure not string";
    return nullopt;
  }
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}
	
	auto elem = state->getElem();
	auto elemobj = Dict::getObject(elem);
	if (!elemobj) {
    BOOST_LOG_TRIVIAL(error) << "element is not object";
    return nullopt;
	}
	return (*elemobj)[*name];
    
}
