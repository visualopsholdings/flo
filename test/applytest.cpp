/*
  applytest.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 14-Oct-2025
    
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"
#include "generic.hpp"

#include <fstream>
#include <rfl/json.hpp>
#include <filesystem>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
namespace fs = std::filesystem;
using namespace flo;

optional<rfl::Object<rfl::Generic> > loadJSON(const string &fn) {

  auto g = rfl::json::load<rfl::Generic>(fn);
  if (!g) {
    cout << g.error().what() << endl;
    return nullopt;
  }
  
  return Generic::getObject(*g);

}

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto file = loadJSON("../test/apply-t.json");
  BOOST_CHECK(file);
  
  auto library = Generic::getVector(file, "library");
  BOOST_CHECK(library);
  auto transform = Generic::getObject(file, "dictionary");
  BOOST_CHECK(transform);
  
  Functions f(*library);
  Processor p(f);

  auto result = p.transform(*transform);
  BOOST_CHECK(result);
//  cout << Generic::toString(*result);
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto type = Generic::getString(obj, "type");
  BOOST_CHECK(type);
  BOOST_CHECK_EQUAL(*type, "online");
  auto pubKey = Generic::getString(obj, "pubKey");
  BOOST_CHECK(pubKey);
  BOOST_CHECK_EQUAL(*pubKey, "a key");

}
