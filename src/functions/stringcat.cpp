/*
  stringcat.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Mar-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "values.hpp"
#include "dict.hpp"
#include "transform.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;
using namespace vops;

template<>
optional<DictG> Func<StringCat>::exec(Transform &transform, State *state, const DictG &closure) {

 BOOST_LOG_TRIVIAL(trace) << "stringcat " << Dict::toString(closure);

  auto a = Dict::getVector(closure);
  if (!a) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
  string str;
	for (auto i: *a) {
		auto value = transform.exec(i, state);
		if (value) {
		  auto s = Dict::getString(*value);
		  if (s) {
		    str = str + *s;
		  }
		}
	}

  return str;
    
}
