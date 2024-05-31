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
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  BOOST_CHECK(result->is_object());
  BOOST_CHECK(result->as_object().if_contains("message"));
  BOOST_CHECK_EQUAL(boost::json::value_to<string>(result->at_pointer("/message")), "hello");
  
}

BOOST_AUTO_TEST_CASE( noFuncTest )
{
  cout << "=== noFuncTest ===" << endl;
  
  json none = {{}};
  Functions f;
  Processor p(none, f);

  json transform = {
    { "xxxx", {} }
  };
  
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  BOOST_CHECK(result->is_object());
  BOOST_CHECK(result->as_object().if_contains("error"));
  BOOST_CHECK_EQUAL(boost::json::value_to<string>(result->at_pointer("/error")), "function xxxx not found");
  
}

BOOST_AUTO_TEST_CASE( ifTrueTest )
{
  cout << "=== ifTrueTest ===" << endl;
  
  json hello = {
    { "message", "hello ignored" }
  };
  Functions f;
  Processor p(hello, f);

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
  
  auto result = p.transform(transform);
  BOOST_CHECK(result);
  BOOST_CHECK(result->is_object());
  BOOST_CHECK(result->as_object().if_contains("message"));
  BOOST_CHECK_EQUAL(boost::json::value_to<string>(result->at_pointer("/message")), "world");
  
}
