/*
  mathtest.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 23-Sep-2026
    
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

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto transform = Utils::loadJSON("math-t.json");
  
  auto input = Processor::getFirstScenarioInput(transform);
  BOOST_CHECK(input);
  
  Functions f(transform);
  Processor p(f);

  // run the scenario.
  auto result = p.transform(transform, *input);
  BOOST_CHECK(result);
  
//  cout << Dict::toString(*result) << endl;
  
  auto l = Dict::getVector(*result);
  BOOST_CHECK(l);
  cout << Dict::toString(*l) << endl;
//   BOOST_CHECK_EQUAL(l->size(), 2);
//   BOOST_CHECK_EQUAL(*Dict::getString((*l)[0]), "aaaa");
//   BOOST_CHECK_EQUAL(*Dict::getString((*l)[1]), "bbbb");
  
}
