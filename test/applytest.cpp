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
#include "../test/utils.hpp"

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace flo;

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto transform = Utils::loadYML("apply-t.yml");
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
  
  auto transform = Utils::loadYML("cur-t.yml");
  BOOST_CHECK(transform);
  
  auto obj = Utils::loadYML("hello.yml");
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
  
  auto transform = Utils::loadJSON("empty-apply-t.json");
  BOOST_CHECK(transform);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform);
  BOOST_CHECK(!result);
  
}

BOOST_AUTO_TEST_CASE( quote )
{
  cout << "=== quote ===" << endl;
  
  auto transform = Utils::loadJSON("quote-t.json");
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
  
  auto transform = Utils::loadJSON("nested-apply-t.json");
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
  
  auto transform = Utils::loadJSON("string-t.json");
  BOOST_CHECK(transform);
  
  auto input = Processor::getFirstScenarioInput(*transform);
  BOOST_CHECK(input);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform, *input);
  BOOST_CHECK(result);
  auto s = Generic::getString(*result);
  BOOST_CHECK(s);
  BOOST_CHECK_EQUAL(*s, "streams");
  
}

BOOST_AUTO_TEST_CASE( nullApply )
{
  cout << "=== nullApply ===" << endl;
  
  auto transform = Utils::loadJSON("null-apply-t.json");
  BOOST_CHECK(transform);
  
  auto input = Processor::getFirstScenarioInput(*transform);
  BOOST_CHECK(input);
  
  Functions f(*transform);
  Processor p(f);

  auto result = p.transform(*transform, *input);
  BOOST_CHECK(!result);
  
}
