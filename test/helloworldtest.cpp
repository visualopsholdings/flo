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

  std::filesystem::path path = "../test";
  if (!std::filesystem::exists(path)) {
    path = "../flo-src/test";
  }

  ifstream file(path.string() + "/" + input);
  BOOST_CHECK(file);
  
  ifstream transform(path.string() + "/hello-t.json");
  BOOST_CHECK(transform);
  
  Functions f;
  Processor p(file, f);
  auto result = p.transform(transform);
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
