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
#include "generic.hpp"

#include <boost/log/trivial.hpp>
#include <iostream>

using namespace flo;

optional<rfl::Generic> Processor::transform(const rfl::Generic &code, std::optional<rfl::Generic> input) {

  auto transform = Generic::getObject(Generic::getObject(code), "transform");
  if (!transform) {
	  BOOST_LOG_TRIVIAL(error) << "no transform input " << Generic::toString(code);
	  return nullopt;
  }
    
  auto tr = Generic::getObject(*transform);
  if (!tr) {
    // if a number, just return that.
    auto num = Generic::getNum(*transform);
    if (num) {
      return *num;
    }
    // if a string, just return that.
    auto s = Generic::getString(*transform);
    if (s) {
      return *s;
    }
    // if a bool, just return that.
    auto b = Generic::getBool(*transform);
    if (b) {
      return *b;
    }
	  BOOST_LOG_TRIVIAL(error) << "transform not object, string, bool or num: " << Generic::toString(*transform);
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
  return t.exec(*tr, &s);

}

optional<rfl::Generic> Processor::transform(const rfl::Generic &code, const std::string &scenario) {

  auto tr = Generic::getObject(code);
  if (!tr) {
    BOOST_LOG_TRIVIAL(error) << "transform is not an object";
    return 1;
  }

  auto scenarios = Generic::getVector(*tr, "scenarios");
  if (!scenarios) {
    BOOST_LOG_TRIVIAL(error) << "no scenarios";
    return nullopt;
  }
  auto sc = find_if(scenarios->begin(), scenarios->end(), [scenario](auto e) {
    auto obj = Generic::getObject(e);
    auto name = Generic::getString(obj, "name");
    if (name) {
      return *name == scenario;
    }
    return false;
  });
  if (sc == scenarios->end()) {
    BOOST_LOG_TRIVIAL(error) << "scenario " << scenario << "not found";
    return nullopt;
  }
  auto obj = Generic::getObject(*sc);
  if (!obj) {
    BOOST_LOG_TRIVIAL(error) << "scenario is not object";
    return nullopt;
  }
  auto input = Generic::getObject(*obj, "input");
  if (!input) {
    BOOST_LOG_TRIVIAL(error) << "scenario has no input";
    return nullopt;
  }
  
  return transform(code, *input);
  
}

optional<rfl::Generic> Processor::getFirstScenarioInput(const rfl::Generic &code) {

  auto scenarios = Generic::getVector(Generic::getObject(code), "scenarios");
  if (!scenarios) {
    BOOST_LOG_TRIVIAL(error) << "scenarios not found";
    return nullopt;
  }
  if (scenarios->size() == 0) {
    BOOST_LOG_TRIVIAL(error) << "need at least 1 scenario";
    return nullopt;
  }
  auto first = Generic::getObject((*scenarios)[0]);
  if (!first) {
    BOOST_LOG_TRIVIAL(error) << "first scenarion not object";
    return nullopt;
  }
  
  return Generic::getGeneric(*first, "input");

}
