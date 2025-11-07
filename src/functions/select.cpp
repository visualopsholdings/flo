/*
  select.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 31-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

//#include "select.hpp"
#include "control.hpp"

#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace vops::flo;
using namespace vops;

template<>
optional<DictG> Func<Select>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "select " << Dict::toString(closure);

  auto a = Dict::getVector(closure);
  if (!a) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
  // select the first function that returns something.
	for (auto i: *a) {
	  auto val = transform.exec(i, state);
	  if (val) {
	    return *val;
	  }
	}

  return nullopt;
    
}
