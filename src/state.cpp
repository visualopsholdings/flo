/*
  state.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "state.hpp"

#include "dict.hpp"

#include <boost/log/trivial.hpp>

using namespace flo;
using namespace vops;

State::State() {
}

State::State(const State &state) {
  _elem = state._elem;
  _coll = state._coll;
}

void State::set(const DictG &g) {
  auto v = Dict::getVector(g);
  if (v) {
    setColl(*v);
  }
  else {
    setElem(g);
  }
}

void State::setElem(const DictG &elem) {

//  BOOST_LOG_TRIVIAL(trace) << "setElem " << Dict::toString(elem);
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

const DictG State::getElem() const {
  return *_elem;
}

void State::setColl(const DictV &coll) {

//  BOOST_LOG_TRIVIAL(trace) << "setColl " << Dict::toString(coll);
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

const vector<DictG> State::getColl() const {
  return *_coll;
}
