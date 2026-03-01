/*
  lengthtest.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 1-Npv-2025
    
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

BOOST_AUTO_TEST_CASE( listLength )
{
  cout << "=== listLength ===" << endl;
  
  auto transform = Utils::loadJSON("list-length-t.json");
  
  auto input = Processor::getFirstScenarioInput(transform);
  BOOST_CHECK(input);
  
  Functions f(transform);
  Processor p(f);

  // run the scenario.
  auto result = p.transform(transform, *input);
  BOOST_CHECK(result);
  auto n = Dict::getNum(*result);
  BOOST_CHECK(n);
  BOOST_CHECK_EQUAL(*n, 4);
    
}

BOOST_AUTO_TEST_CASE( stringLength )
{
  cout << "=== stringLength ===" << endl;
  
  auto transform = Utils::loadJSON("string-length-t.json");
  
  auto input = Processor::getFirstScenarioInput(transform);
  BOOST_CHECK(input);
  
  Functions f(transform);
  Processor p(f);

  // run the scenario.
  auto result = p.transform(transform, *input);
  BOOST_CHECK(result);
  auto n = Dict::getNum(*result);
  BOOST_CHECK(n);
  BOOST_CHECK_EQUAL(*n, 5);
    
}
