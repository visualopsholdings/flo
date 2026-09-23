/*
  divide.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 23-Sep-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "math.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace vops::flo;

template<>
optional<DictG> Func<Divide>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "divide " << Dict::toString(closure);

  auto v = Dict::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not a list";
    return nullopt;
  }
  if (v->size() != 2) {
    BOOST_LOG_TRIVIAL(error) << "list doesn't have 2 elements";
    return nullopt;
  }
	auto n1g = transform.exec((*v)[0], state);
	if (!n1g) {
	  return 0;
	}
	auto n2g = transform.exec((*v)[1], state);
	if (!n2g) {
	  return 0; // really undefined!
	}
  auto n1 = Dict::getNum(*n1g);
  auto n2 = Dict::getNum(*n2g);
	if (!n1 || !n2) {
	  return 0;
	}
  
  return  *n1 / *n2;
       
}
