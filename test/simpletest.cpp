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
#include "dict.hpp"
#include "utils.hpp"

#include <fstream>
#include <rfl/json.hpp>
#include <filesystem>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
namespace fs = std::filesystem;
using namespace vops::flo;
using namespace vops;

BOOST_AUTO_TEST_CASE( nullTest )
{
  cout << "=== nullTest ===" << endl;
  
  auto hello = Utils::loadJSON("hello.json");
//  cout << rfl::json::write<DictG>(hello) << endl;
  
  auto transform = Utils::loadJSON("null-t.json");

  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform, hello);
  BOOST_CHECK(result);
  
  auto obj = Dict::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Dict::getString(obj, "message");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "hello");
  
}

BOOST_AUTO_TEST_CASE( noFuncTest )
{
  cout << "=== noFuncTest ===" << endl;
  
  auto transform = Utils::loadJSON("bad-t.json");
  
  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  
  auto obj = Dict::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Dict::getString(obj, "error");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "function xxxx not found");
  
}

BOOST_AUTO_TEST_CASE( ifTrueTest )
{
  cout << "=== ifTrueTest ===" << endl;
  
  auto hello = Utils::loadJSON("message.json");
  
  auto transform = Utils::loadJSON("true-t.json");
  
  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform, hello);
  BOOST_CHECK(result);
  
  auto obj = Dict::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Dict::getString(obj, "message");
  BOOST_CHECK(m);
  BOOST_CHECK_EQUAL(*m, "world");
  
}
