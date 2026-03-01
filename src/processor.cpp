/*
  processor.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "processor.hpp"

#include "functions.hpp"
#include "state.hpp"
#include "transform.hpp"
#include "dict.hpp"

#include <boost/log/trivial.hpp>
#include <iostream>

using namespace vops::flo;
using namespace vops;

optional<DictG> Processor::transform(const DictG &code, std::optional<DictG> input, std::optional<DictO> args) {

  auto transform = Dict::getGeneric(Dict::getObject(code), "transform");
  if (!transform) {
	  BOOST_LOG_TRIVIAL(error) << "no transform input " << Dict::toString(code);
	  return nullopt;
  }
    
  auto tr = Dict::getObject(*transform);
  if (!tr) {
    // if a number, just return that.
    auto num = Dict::getNum(*transform);
    if (num) {
      return *num;
    }
    // if a string, just return that.
    auto s = Dict::getString(*transform);
    if (s) {
      return *s;
    }
    // if a bool, just return that.
    auto b = Dict::getBool(*transform);
    if (b) {
      return *b;
    }
	  BOOST_LOG_TRIVIAL(error) << "transform not object, string, bool or num: " << Dict::toString(*transform);
	  return nullopt;
  }
  if (tr->size() == 0) {
	  BOOST_LOG_TRIVIAL(trace) << "object is empty";
	  return nullopt;
  }
  
  Transform t(_functions);
  State s;
  if (input) {
    s.set(*input);
  }
  if (args) {
    s.setArgs(*args);
  }
  return t.exec(*tr, &s);

}

optional<DictG> Processor::transform(const DictG &code, const std::string &scenario) {

  auto tr = Dict::getObject(code);
  if (!tr) {
    BOOST_LOG_TRIVIAL(error) << "transform is not an object";
    return 1;
  }

  auto scenarios = Dict::getVector(*tr, "scenarios");
  if (!scenarios) {
    BOOST_LOG_TRIVIAL(error) << "no scenarios";
    return nullopt;
  }
  auto sc = find_if(scenarios->begin(), scenarios->end(), [scenario](auto e) {
    auto obj = Dict::getObject(e);
    auto name = Dict::getString(obj, "name");
    if (name) {
      return *name == scenario;
    }
    return false;
  });
  if (sc == scenarios->end()) {
    BOOST_LOG_TRIVIAL(error) << "scenario " << scenario << "not found";
    return nullopt;
  }
  auto obj = Dict::getObject(*sc);
  if (!obj) {
    BOOST_LOG_TRIVIAL(error) << "scenario is not object";
    return nullopt;
  }
  auto input = Dict::getObject(*obj, "input");
  if (!input) {
    BOOST_LOG_TRIVIAL(error) << "scenario has no input";
    return nullopt;
  }
  
  return transform(code, *input);
  
}

optional<DictG> Processor::getFirstScenarioInput(const DictG &code) {

  auto scenarios = Dict::getVector(Dict::getObject(code), "scenarios");
  if (!scenarios) {
    BOOST_LOG_TRIVIAL(error) << "scenarios not found";
    return nullopt;
  }
  if (scenarios->size() == 0) {
    BOOST_LOG_TRIVIAL(error) << "need at least 1 scenario";
    return nullopt;
  }
  auto first = Dict::getObject((*scenarios)[0]);
  if (!first) {
    BOOST_LOG_TRIVIAL(error) << "first scenarion not object";
    return nullopt;
  }
  
  return Dict::getGeneric(*first, "input");

}
