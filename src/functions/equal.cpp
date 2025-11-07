/*
  equal.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "transform.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;
using namespace vops;

template<>
optional<DictG> Func<Equal>::exec(Transform &transform, State *state, const DictG &closure) {

//  BOOST_LOG_TRIVIAL(trace) << "equal " << Dict::toString(closure);

  auto a = Dict::getVector(closure);
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
		if (!lvalue || !rvalue || (Dict::getString(*lvalue) != Dict::getString(*rvalue))) {
			return false;
		}
		i++;
	}
  return true;
    
}
