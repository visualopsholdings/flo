/*
  state.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "state.hpp"

State::State(): _elem(0) {
}

State::State(const State &state) {
  _elem = state._elem;
}

void State::setElem(boost::json::object &elem) {
  _elem = elem;
}

bool State::hasElem() const {
  return _elem != 0;
}

const boost::json::object State::getElem() const {
  return *_elem;
}
