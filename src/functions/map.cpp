/*
  map.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions/map.hpp"

Map::Map() {

}

json Map::exec(Transform &transform, State &state) {

  return {{}};
  
}

shared_ptr<Function> Map::create() {

  return shared_ptr<Function>(new Map());
  
}
