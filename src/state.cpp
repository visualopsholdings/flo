/*
  state.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "state.hpp"

#include "generic.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;

State::State() {
}

State::State(const State &state) {
  _elem = state._elem;
  _coll = state._coll;
}

void State::set(const rfl::Generic &g) {
  auto v = Generic::getVector(g);
  if (v) {
    setColl(*v);
  }
  else {
    setElem(g);
  }
}

void State::setElem(const rfl::Generic &elem) {

//  BOOST_LOG_TRIVIAL(trace) << "setElem " << Generic::toString(elem);
  BOOST_LOG_TRIVIAL(trace) << "setElem";
  _elem = elem;
  
}

void State::clearElem() {

  BOOST_LOG_TRIVIAL(trace) << "clearElem";
  _elem = nullopt;
  
}

bool State::hasElem() const {
  return _elem != nullopt;
}

const rfl::Generic State::getElem() const {
  return *_elem;
}

void State::setColl(const std::vector<rfl::Generic> &coll) {

//  BOOST_LOG_TRIVIAL(trace) << "setColl " << Generic::toString(coll);
  BOOST_LOG_TRIVIAL(trace) << "setColl";
  _coll = coll;
  
}

void State::clearColl() {

  BOOST_LOG_TRIVIAL(trace) << "clearColl";
  _coll = nullopt;
  
}

bool State::hasColl() const {
  return _coll != nullopt;
}

const vector<rfl::Generic> State::getColl() const {
  return *_coll;
}
