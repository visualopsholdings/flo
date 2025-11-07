/*
  libtest.cpp
  
  Author: Paul Hamilton (phamtec@mac.com)
  Date: 13-Oct-2025
    
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include <iostream>

#include "processor.hpp"
#include "functions.hpp"
#include "dict.hpp"

#include <fstream>
#include <rfl/json.hpp>
#include <filesystem>

#define BOOST_AUTO_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;
namespace fs = std::filesystem;
using namespace flo;
using namespace vops;

optional<DictO > loadJSON(const string &fn) {

  std::filesystem::path path = "../test";
  if (!std::filesystem::exists(path)) {
    path = "../flo-src/test";
  }

  auto g = rfl::json::load<DictG>(path.string() + "/" + fn);
  if (!g) {
    cout << g.error().what() << endl;
    return nullopt;
  }
  
  return Dict::getObject(*g);

}

BOOST_AUTO_TEST_CASE( simple )
{
  cout << "=== simple ===" << endl;
  
  auto file = loadJSON("library-t.json");
  BOOST_CHECK(file);
  
  Functions f(*file);
  Processor p(f);

  auto result = p.transform(*file);
  BOOST_CHECK(result);
  auto s = Dict::getString(*result);
  BOOST_CHECK(s);
  BOOST_CHECK_EQUAL(*s, "a key");
  
}
