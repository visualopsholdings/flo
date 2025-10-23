/*
  helloworldtest.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"
#include "generic.hpp"

#include <fstream>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace flo;

void runTransform(const string &input, const string &message) {

  std::filesystem::path path = "../flo-src/test";
  if (!std::filesystem::exists(path)) {
    path = "../test";
  }

  ifstream fs(path.string() + "/" + input);
  BOOST_CHECK(fs);
  auto file = Generic::parseStream(fs, ".json");
  BOOST_CHECK(file);
  
  ifstream t(path.string() + "/hello-t.json");
  BOOST_CHECK(t);
  auto transform = Generic::parseStream(t, ".json");
  BOOST_CHECK(transform);
  
  Functions f(*transform);
  Processor p(f);
  auto result = p.transform(*transform, *file);
  BOOST_CHECK(result);
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto m = Generic::getString(obj, "message");
  BOOST_CHECK(m);
	BOOST_CHECK_EQUAL(*m, message);

}

BOOST_AUTO_TEST_CASE( helloWorld )
{
  cout << "=== helloWorld ===" << endl;
  
  runTransform("hello.json", "world");

}

BOOST_AUTO_TEST_CASE( otherMsg )
{
  cout << "=== otherMsg ===" << endl;
  
  runTransform("message.json", "a message");

}
