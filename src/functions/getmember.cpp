/*
  getmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "data.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

template<>
optional<rfl::Generic> Func<GetMember>::exec(Transform &transform, State *state, const rfl::Generic &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "getmember " << Generic::toString(closure);

  auto obj = Generic::getObject(closure);
  if (!obj) {
    BOOST_LOG_TRIVIAL(error) << "closure not object";
    return nullopt;
  }
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}
	
  auto name = Generic::getString(*obj, "name");
  if (!name) {
    BOOST_LOG_TRIVIAL(error) << "missing name";
    return nullopt;
  }
	auto elem = state->getElem();
	auto elemobj = Generic::getObject(elem);
	if (!elemobj) {
    BOOST_LOG_TRIVIAL(error) << "element is not object";
    return nullopt;
	}
	return (*elemobj)[*name];
    
}
