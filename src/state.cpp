/*
  state.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "state.hpp"

State::State() {
}

State::State(const State &state) {
  _elem = state._elem;
}

void State::setElem(rfl::Object<rfl::Generic> &elem) {
  _elem = elem;
}

bool State::hasElem() const {
  return _elem != nullopt;
}

const rfl::Object<rfl::Generic> State::getElem() const {
  return *_elem;
}
