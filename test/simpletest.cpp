/*
  simpletest.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"

#include <fstream>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE( hello )
{
  cout << "=== hello ===" << endl;
  
  ifstream file("../test/hello.json");
  BOOST_CHECK(file);
  
  ifstream transform("../test/hello-t.json");
  BOOST_CHECK(transform);
  
  Functions f;
  Processor p(file);
  Processor::pretty_print(cout, p.transform(transform));

}
