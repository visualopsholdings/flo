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

BOOST_AUTO_TEST_CASE( helloWorld )
{
  cout << "=== helloWorld ===" << endl;
  
  ifstream file("../test/hello.json");
  BOOST_CHECK(file);
  
  ifstream transform("../test/hello-t.json");
  BOOST_CHECK(transform);
  
  Functions f;
  Processor p(file, f);
  auto result = p.transform(transform);
  BOOST_CHECK(!result);
//  BOOST_CHECK(result->as_object().if_contains("error"));
//  BOOST_CHECK_EQUAL(boost::json::value_to<string>(result->at_pointer("/error")), "equal not implemented");

}
