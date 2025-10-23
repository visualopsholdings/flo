/*
  simpletest.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
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

rfl::Generic loadJSON(const string &fn) {

  std::filesystem::path path = "../flo-src/test";
  if (!std::filesystem::exists(path)) {
    path = "../test";
  }

  auto g = rfl::json::load<rfl::Generic>(path.string() + "/" + fn);
  if (!g) {
    cout << g.error().what() << endl;
    return 0;
  }
  return *g;

}

BOOST_AUTO_TEST_CASE( nullTest )
{
  cout << "=== nullTest ===" << endl;
  
  auto hello = loadJSON("hello.json");
//  cout << rfl::json::write<rfl::Generic>(hello) << endl;
  
  auto transform = loadJSON("null-t.json");

  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform, hello);
  BOOST_CHECK(result);
  
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Generic::getString(obj, "message");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "hello");
  
}

BOOST_AUTO_TEST_CASE( noFuncTest )
{
  cout << "=== noFuncTest ===" << endl;
  
  auto transform = loadJSON("bad-t.json");
  
  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Generic::getString(obj, "error");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "function xxxx not found");
  
}

BOOST_AUTO_TEST_CASE( ifTrueTest )
{
  cout << "=== ifTrueTest ===" << endl;
  
  auto hello = loadJSON("message.json");
  
  auto transform = loadJSON("true-t.json");
  
  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform, hello);
  BOOST_CHECK(result);
  
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Generic::getString(obj, "message");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "world");
  
}
