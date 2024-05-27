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

BOOST_AUTO_TEST_CASE( nullTest )
{
  cout << "=== nullTest ===" << endl;
  
  json hello = {
    { "message", "hello" }
  };
  Functions f;
  Processor p(hello,f);

  json transform = {
    { "null", {} }
  };
  json result = p.transform(transform);
  BOOST_CHECK(result.as_object().if_contains("message"));
  BOOST_CHECK_EQUAL(boost::json::value_to<string>(result.at_pointer("/message")), "hello");
  
}

BOOST_AUTO_TEST_CASE( ifTrueTest )
{
  cout << "=== ifTest ===" << endl;
  
  json hello = {
    { "message", "hello ignored" }
  };
  Functions f;
  Processor p(hello,f);

  json transform = {
    { "if", {
        { "p", {
            { "true", {} }
          }
        },
        { "then", {
            { "dict", {
              { "message", "world" }
              } 
            }
          }
        }
      } 
    }
  };
  cout << transform << endl;
  
  json result = p.transform(transform);
  BOOST_CHECK(result.as_object().if_contains("message"));
  BOOST_CHECK_EQUAL(boost::json::value_to<string>(result.at_pointer("/message")), "world");
  
}

// BOOST_AUTO_TEST_CASE( helloWorld )
// {
//   cout << "=== helloWorld ===" << endl;
//   
//   ifstream file("../test/hello.json");
//   BOOST_CHECK(file);
//   
//   ifstream transform("../test/hello-t.json");
//   BOOST_CHECK(transform);
//   
//   Functions f;
//   Processor p(file, f);
//   json result = p.transform(transform);
//   BOOST_CHECK(result.as_object().if_contains("message"));
//   BOOST_CHECK_EQUAL(boost::json::value_to<string>(result.at_pointer("/message")), "world");
// 
// }
