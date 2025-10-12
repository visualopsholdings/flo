/*
  simpletest.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"
#include "reflect.hpp"

#include <fstream>
#include <rfl/json.hpp>
#include <filesystem>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
namespace fs = std::filesystem;

rfl::Generic loadJSON(const string &fn) {

  auto g = rfl::json::load<rfl::Generic>(fn);
  if (!g) {
    cout << g.error().what() << endl;
    return 0;
  }
  return *g;

}

BOOST_AUTO_TEST_CASE( nullTest )
{
  cout << "=== nullTest ===" << endl;
  
  auto hello = loadJSON("../test/hello.json");
//  cout << rfl::json::write<rfl::Generic>(hello) << endl;
  
  Functions f;
  Processor p(hello, f);

  auto transform = loadJSON("../test/null-t.json");
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  auto obj = Reflect::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Reflect::getString(obj, "message");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "hello");
  
}

BOOST_AUTO_TEST_CASE( noFuncTest )
{
  cout << "=== noFuncTest ===" << endl;
  
  auto none = loadJSON("../test/null.json");
  Functions f;
  Processor p(none, f);

  auto transform = loadJSON("../test/bad-t.json");
  
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  auto obj = Reflect::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Reflect::getString(obj, "error");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "function xxxx not found");
  
}

BOOST_AUTO_TEST_CASE( ifTrueTest )
{
  cout << "=== ifTrueTest ===" << endl;
  
  auto hello = loadJSON("../test/message.json");
  
  Functions f;
  Processor p(hello, f);

  auto transform = loadJSON("../test/true-t.json");
  
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  auto obj = Reflect::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Reflect::getString(obj, "message");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "world");
  
}
