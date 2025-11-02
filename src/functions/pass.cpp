/*
  pass.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 15-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

template<>
optional<rfl::Generic> Func<Pass>::exec(Transform &transform, State *state, const rfl::Generic &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "select " << Generic::toString(closure);

  auto a = Generic::getVector(closure);
  if (!a) {
    BOOST_LOG_TRIVIAL(error) << "closure not array";
    return nullopt;
  }
  
  // select the first function that returns something.
  optional<rfl::Generic> last;
	for (auto i: *a) {
	  // throw away everything but the last result.
	  last = transform.exec(i, state);
	}

  return last;
      
}
