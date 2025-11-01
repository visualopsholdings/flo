/*
  utils.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "../test/utils.hpp"

#include "generic.hpp"

#include <rfl/yaml.hpp>
#include <rfl/json.hpp>

using namespace std;
using flo::Generic;

optional<rfl::Object<rfl::Generic> > Utils::loadYML(const string &fn) {

  std::filesystem::path path = "../flo-src/test";
  if (!std::filesystem::exists(path)) {
    path = "../test";
  }

  auto g = rfl::yaml::load<rfl::Generic>(path.string() + "/" + fn);
  if (!g) {
    cout << g.error().what() << endl;
    return nullopt;
  }
  
  return Generic::getObject(*g);

}

optional<rfl::Object<rfl::Generic> > Utils::loadJSON(const string &fn) {

  std::filesystem::path path = "../flo-src/test";
  if (!std::filesystem::exists(path)) {
    path = "../test";
  }

  auto g = rfl::json::load<rfl::Generic>(path.string() + "/" + fn);
  if (!g) {
    cout << g.error().what() << endl;
    return nullopt;
  }
  
  return Generic::getObject(*g);

}

