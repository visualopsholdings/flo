/*
  applytest.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 14-Oct-2025
    
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"
#include "generic.hpp"

#include <fstream>
#include <rfl/yaml.hpp>
#include <rfl/json.hpp>
#include <filesystem>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
namespace fs = std::filesystem;
using namespace flo;

optional<rfl::Object<rfl::Generic> > loadYML(const string &fn) {

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

optional<rfl::Object<rfl::Generic> > loadJSON(const string &fn) {

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

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto transform = loadYML("apply-t.yml");
  BOOST_CHECK(transform);
  
  Functions f(*transform);
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

BOOST_AUTO_TEST_CASE( cur )
{
  cout << "=== cur ===" << endl;
  
  auto transform = loadYML("cur-t.yml");
  BOOST_CHECK(transform);
  
  auto obj = loadYML("hello.yml");
  BOOST_CHECK(obj);

  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform, *obj);
  BOOST_CHECK(result);
  auto s = Generic::getString(*result);
  BOOST_CHECK(s);
  BOOST_CHECK_EQUAL(*s, "hello");
  
}

BOOST_AUTO_TEST_CASE( emptyApply )
{
  cout << "=== emptyApply ===" << endl;
  
  auto transform = loadJSON("empty-apply-t.json");
  BOOST_CHECK(transform);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform);
  BOOST_CHECK(!result);
  
}

BOOST_AUTO_TEST_CASE( quote )
{
  cout << "=== quote ===" << endl;
  
  auto transform = loadJSON("quote-t.json");
  BOOST_CHECK(transform);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform);
  BOOST_CHECK(result);
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto apply = Generic::getVector(obj, "apply");
  BOOST_CHECK(apply);
  
}

BOOST_AUTO_TEST_CASE( nested )
{
  cout << "=== nested ===" << endl;
  
  auto transform = loadJSON("nested-apply-t.json");
  BOOST_CHECK(transform);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform);
  BOOST_CHECK(result);
  auto obj = Generic::getObject(*result);
  auto t = Generic::getString(Generic::getObject(obj, "send"), "type");
  BOOST_CHECK(t);
  BOOST_CHECK_EQUAL(*t, "xxxx");
  t = Generic::getString(Generic::getObject(obj, "next"), "type");
  BOOST_CHECK(t);
  BOOST_CHECK_EQUAL(*t, "yyyy");
  
}

BOOST_AUTO_TEST_CASE( stringResult )
{
  cout << "=== stringResult ===" << endl;
  
  auto transform = loadJSON("string-t.json");
  BOOST_CHECK(transform);
  
  auto scenarios = Generic::getVector(*transform, "scenarios");
  BOOST_CHECK(scenarios);
  auto simple = Generic::getObject((*scenarios)[0]);
  BOOST_CHECK(simple);
  auto input = Generic::getObject(*simple, "input");
  BOOST_CHECK(input);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform, *input);
  BOOST_CHECK(result);
  auto s = Generic::getString(*result);
  BOOST_CHECK(s);
  BOOST_CHECK_EQUAL(*s, "streams");
  
}
