/*
  equal.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "transform.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

template<>
optional<rfl::Generic> Func<Equal>::exec(Transform &transform, State *state, const rfl::Generic &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "equal " << Generic::toString(closure);

  auto a = Generic::getVector(closure);
  if (!a) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
	auto i = a->begin();
	auto head = *i;
	auto lvalue = transform.exec(head, state);
	i++;
	while (i != a->end()) {
		auto rvalue = transform.exec(*i, state);
		if (!lvalue || !rvalue || (Generic::getString(*lvalue) != Generic::getString(*rvalue))) {
			return false;
		}
		i++;
	}
  return true;
    
}
