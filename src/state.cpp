/*
  state.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "state.hpp"

State::State(): _coll(0), _elem(0) {
}

State::State(const State &state) {
  _coll = state._coll;
  _elem = state._elem;
}

int State::arity() const {
  return !_coll ? (!_elem ? 0 : 1) : 2;
}

void State::setColl(json *coll) {
  _coll = coll;
}

bool State::hasColl() const {
  return _coll;
}

const json &State::coll() const{
  return *_coll;
}

void State::setElem(json *elem) {
  _elem = elem;
}

bool State::hasElem() const {
  return _elem;
}

const json &State::elem() const {
  return *_elem;
}
