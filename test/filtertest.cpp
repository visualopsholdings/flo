/*
  filtertest.cpp
  
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
  
  auto transform = Utils::loadJSON("filter-t.json");
  BOOST_CHECK(transform);
  
  auto input = Processor::getFirstScenarioInput(*transform);
  BOOST_CHECK(input);
  
  Functions f(*transform);
  Processor p(f);

  // run the scenario.
  auto result = p.transform(*transform, *input);
  BOOST_CHECK(result);
  
//  cout << Generic::toString(*result) << endl;
  
  auto obj = Generic::getObject(*result);
  BOOST_CHECK(obj);
  auto n = Generic::getString(obj, "name");
  BOOST_CHECK(n);
  BOOST_CHECK_EQUAL(*n, "Joe");
  
}
