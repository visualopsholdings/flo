/*
  helloworld.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 30-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"

#include <fstream>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

void runTransform(const string &input, const string &message) {

  ifstream file(input);
  BOOST_CHECK(file);
  
  ifstream transform("../test/hello-t.json");
  BOOST_CHECK(transform);
  
  Functions f;
  Processor p(file, f);
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  BOOST_CHECK(result->as_object().if_contains("message"));
	BOOST_CHECK_EQUAL(boost::json::value_to<string>(result->at_pointer("/message")), message);

}

BOOST_AUTO_TEST_CASE( helloWorld )
{
  cout << "=== helloWorld ===" << endl;
  
  runTransform("../test/hello.json", "world");

}

BOOST_AUTO_TEST_CASE( otherMsg )
{
  cout << "=== otherMsg ===" << endl;
  
  runTransform("../test/message.json", "a message");

}
