/*
  argtest.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Mar-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"
#include "dict.hpp"
#include "utils.hpp"

#include <fstream>
#include <rfl/json.hpp>
#include <filesystem>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
namespace fs = std::filesystem;
using namespace vops::flo;
using namespace vops;

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto hello = Utils::loadJSON("message.json");
  auto transform = Utils::loadJSON("arg-t.json");

  Functions f(transform);
  Processor p(f);
  auto result = p.transform(transform, hello);
  BOOST_CHECK(result);
  
  auto string = Dict::getString(*result);
  BOOST_CHECK(string);
  BOOST_CHECK_EQUAL(*string, "hello");

}

