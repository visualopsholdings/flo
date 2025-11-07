/*
  setmember.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "data.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;
using namespace vops;

template<>
optional<DictG> Func<SetMember>::exec(Transform &transform, State *state, const DictG &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "setmember " << Dict::toString(closure);

  auto obj = Dict::getObject(closure);
  if (!obj) {
    BOOST_LOG_TRIVIAL(error) << "closure not object";
    return nullopt;
  }
	if (!state->hasElem()) {
    BOOST_LOG_TRIVIAL(error) << "state has no elem";
    return nullopt;
	}

  auto name = Dict::getString(obj, "name");
  if (!name) {
    BOOST_LOG_TRIVIAL(error) << "missing name";
    return nullopt;
  }
  auto v = Dict::getGeneric(obj, "value");
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "missing value";
    return nullopt;
  }
	auto elem = state->getElem();
	auto elemobj = Dict::getObject(elem);
	if (!elemobj) {
    BOOST_LOG_TRIVIAL(error) << "element is not object";
    return nullopt;
	}
  auto value = transform.exec(*v, state);
  if (value) {
    (*elemobj)[*name] = *value;
    return *elemobj;
  }

  BOOST_LOG_TRIVIAL(error) << "not sure how to erase an element in Object";
  return nullopt;
    
}
