/*
  maptest.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 1-Npv-2025
    
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
  
  auto transform = Utils::loadJSON("map-t.json");
  BOOST_CHECK(transform);
  
  auto input = Processor::getFirstScenarioInput(*transform);
  BOOST_CHECK(input);
  
  Functions f(*transform);
  Processor p(f);

  // run the scenario.
  auto result = p.transform(*transform, *input);
  BOOST_CHECK(result);
  auto v = Generic::getVector(*result);
  BOOST_CHECK(v);
  BOOST_CHECK_EQUAL(v->size(), 3);
  auto n = Generic::getString((*v)[0]);
  BOOST_CHECK(n);
  BOOST_CHECK_EQUAL(*n, "Fred");
  n = Generic::getString((*v)[1]);
  BOOST_CHECK(n);
  BOOST_CHECK_EQUAL(*n, "Joe");
  n = Generic::getString((*v)[2]);
  BOOST_CHECK(n);
  BOOST_CHECK_EQUAL(*n, "Bill");
  
}
