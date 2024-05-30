/*
  map.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/map.hpp"

#include "state.hpp"
#include "transform.hpp"

#include <iostream>
#include <algorithm>

Map::Map() {

}

json Map::exec(const Transform &transform, State *state, const json &closure) {

//   if (state->hasColl()) {
//     boost::json::array a = state->coll().as_array();
//     vector<optional<json> > new_values;
//     std::transform(a.begin(), a.end(), back_inserter(new_values), 
//       [this, transform, &state, closure](json& e) {
//         State local(*state);
//         return apply(transform, &local, closure); 
//       }
//     );
// //     boost::json::object newo;
// //     for (auto i: new_values) {
// //       newo[i.key()] = i.value();
// //     }
// //    return newo;
//   }
  
  return { { "message", "map not implemented" } };
    
}

shared_ptr<Function> Map::create() {

  return shared_ptr<Function>(new Map());
  
}

// optional<json> Map::apply(const Transform &transform, State *state, const json &closure) {
// 
//   int arity = state->arity();
//   for (auto i: closure.as_array()) {
//     auto val = transform.get_value(state, i);
//     if (val && (*val).is_array()) {
//       state->setColl(&(*val));
//       state->setElem(0);
//       arity = 2;
//     }
//     else {
//       state->setColl(0);
//       state->setElem(&(*val));
//       arity = 1;
//     }
//   }
//   
//   switch (arity) {
//     case 2:
//       return state->coll();
//       
//     case 1:
//       return state->elem();
//   }
//   
//   return nullopt;
//   
// }
