/*
  multiply.cpp
  
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
using namespace vops;

template<>
optional<DictG> Func<Multiply>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "divide " << Dict::toString(closure);

  auto v = Dict::getVector(closure);
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "closure not a list";
    return nullopt;
  }
  if (v->size() < 1) {
    return 0;
  }
  auto i = v->begin();
  double acc = evalDouble(transform, state, *i);
  i++;
  for (; i != v->end(); i++) {
    acc *= evalDouble(transform, state, *i);
  }
  
  return acc;
       
}
