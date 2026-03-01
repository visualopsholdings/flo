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
#include "dict.hpp"
#include "../test/utils.hpp"

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace vops::flo;
using namespace vops;

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto transform = Utils::loadYML("apply-t.yml");
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform);
  BOOST_CHECK(result);
//  cout << Dict::toString(*result);
  auto obj = Dict::getObject(*result);
  BOOST_CHECK(obj);
  auto type = Dict::getString(obj, "type");
  BOOST_CHECK(type);
  BOOST_CHECK_EQUAL(*type, "online");
  auto pubKey = Dict::getString(obj, "pubKey");
  BOOST_CHECK(pubKey);
  BOOST_CHECK_EQUAL(*pubKey, "a key");

}

BOOST_AUTO_TEST_CASE( cur )
{
  cout << "=== cur ===" << endl;
  
  auto transform = Utils::loadYML("cur-t.yml");
  
  auto obj = Utils::loadYML("hello.yml");

  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform, obj);
  BOOST_CHECK(result);
  auto s = Dict::getString(*result);
  BOOST_CHECK(s);
  BOOST_CHECK_EQUAL(*s, "hello");
  
}

BOOST_AUTO_TEST_CASE( emptyApply )
{
  cout << "=== emptyApply ===" << endl;
  
  auto transform = Utils::loadJSON("empty-apply-t.json");
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform);
  BOOST_CHECK(!result);
  
}

BOOST_AUTO_TEST_CASE( quote )
{
  cout << "=== quote ===" << endl;
  
  auto transform = Utils::loadJSON("quote-t.json");
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform);
  BOOST_CHECK(result);
  auto obj = Dict::getObject(*result);
  BOOST_CHECK(obj);
  auto apply = Dict::getVector(obj, "apply");
  BOOST_CHECK(apply);
  
}

BOOST_AUTO_TEST_CASE( nested )
{
  cout << "=== nested ===" << endl;
  
  auto transform = Utils::loadJSON("nested-apply-t.json");
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform);
  BOOST_CHECK(result);
  auto obj = Dict::getObject(*result);
  auto t = Dict::getString(Dict::getObject(obj, "send"), "type");
  BOOST_CHECK(t);
  BOOST_CHECK_EQUAL(*t, "xxxx");
  t = Dict::getString(Dict::getObject(obj, "next"), "type");
  BOOST_CHECK(t);
  BOOST_CHECK_EQUAL(*t, "yyyy");
  
}

BOOST_AUTO_TEST_CASE( stringResult )
{
  cout << "=== stringResult ===" << endl;
  
  auto transform = Utils::loadJSON("string-t.json");
  
  auto input = Processor::getFirstScenarioInput(transform);
  BOOST_CHECK(input);
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform, *input);
  BOOST_CHECK(result);
  auto s = Dict::getString(*result);
  BOOST_CHECK(s);
  BOOST_CHECK_EQUAL(*s, "streams");
  
}

BOOST_AUTO_TEST_CASE( nullApply )
{
  cout << "=== nullApply ===" << endl;
  
  auto transform = Utils::loadJSON("null-apply-t.json");
  
  auto input = Processor::getFirstScenarioInput(transform);
  BOOST_CHECK(input);
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform, *input);
  BOOST_CHECK(!result);
  
}

BOOST_AUTO_TEST_CASE( applyMask )
{
  cout << "=== applyMask ===" << endl;
  
  auto transform = Utils::loadJSON("apply-mask-t.json");
  
  auto input = Processor::getFirstScenarioInput(transform);
  BOOST_CHECK(input);
  
  Functions f(transform);
  Processor p(f);

  auto result = p.transform(transform, *input);
  BOOST_CHECK(result);
  cout << Dict::toString(*result) << endl;
  auto v = Dict::getVector(*result);
  BOOST_CHECK(v);
  BOOST_CHECK_EQUAL(v->size(), 3);
  auto v2 = Dict::getVector((*v)[0]);
  BOOST_CHECK(v2);
  BOOST_CHECK_EQUAL(v2->size(), 1);
  auto id = Dict::getString(Dict::getObject(Dict::getObject((*v2)[0]), "idShouldNotBeNull"), "id");
  BOOST_CHECK(id);

  
}
