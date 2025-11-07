/*
  dict.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "list.hpp"
#include "dict.hpp"
#include "state.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;
using namespace vops;

template<>
optional<DictG> Func<flo::Dict>::exec(Transform &transform, State *state, const DictG &closure) {
  
  using vops::Dict;
  
//  BOOST_LOG_TRIVIAL(trace) << "Dict exec " << Dict::toString(closure);
  
  auto obj = Dict::getObject(closure);
  if (obj) {
    if (obj->size() == 0) {
      BOOST_LOG_TRIVIAL(trace) << "empty closure";
      if (state->hasColl()) {
        BOOST_LOG_TRIVIAL(trace) << "state is a vector";
        // we convert name value pairs in the vector to dictionary entries.
        auto v = state->getColl();
//        BOOST_LOG_TRIVIAL(trace) << "turning to dict " << Dict::toString(v);
        DictO obj;
        for (auto i: v) {
          auto v2 = Dict::getVector(i);
          if (v2 && v2->size() == 2) {
            auto name = Dict::getString(*v2->begin());
            if (!name) {
              BOOST_LOG_TRIVIAL(error) << "first in pair must be name";
              return nullopt;
            }
            BOOST_LOG_TRIVIAL(trace) << *name << "=";
            obj[*name] = *(v2->begin() + 1);
          }
        }
        return obj;
      }
      return nullopt;
    }
     
    return *obj;
  }
  
  // closure is not a dictionary.
  return nullopt;
  
}
