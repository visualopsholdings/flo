/*
  state.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "state.hpp"

using namespace flo;

State::State() {
}

State::State(const State &state) {
  _elem = state._elem;
  _coll = state._coll;
}

void State::setElem(const rfl::Generic &elem) {
  _elem = elem;
}

void State::clearElem() {
  _elem = nullopt;
}

bool State::hasElem() const {
  return _elem != nullopt;
}

const rfl::Generic State::getElem() const {
  return *_elem;
}

void State::setColl(const std::vector<rfl::Generic> &coll) {
  _obj = nullopt;
  _coll = coll;
}

void State::clearColl() {
  _obj = nullopt;
  _coll = nullopt;
}

bool State::hasColl() const {
  return _coll != nullopt;
}

const vector<rfl::Generic> State::getColl() const {
  return *_coll;
}

void State::setColl(const rfl::Object<rfl::Generic> &obj) {
  _obj = obj;
  _coll = nullopt;
}

bool State::hasObj() const {
  return _obj != nullopt;
}

const rfl::Object<rfl::Generic> State::getObj() const {
  return *_obj;
}
