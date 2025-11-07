/*
  functions.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "functions.hpp"

#include "control.hpp"
#include "values.hpp"
#include "list.hpp"
#include "data.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace flo;
using namespace vops;

Functions::Functions(const DictG &transform) {

  using vops::Dict;
  
  loadFunctions();

  // if there is a library in the transform, then use that.
  auto library = Dict::getVector(Dict::getObject(transform), "library");
  if (!library) {
	  BOOST_LOG_TRIVIAL(trace) << "library not found in transform" << endl;
	  return;
  }
  
  for (auto i: *library) {
    auto obj = Dict::getObject(i);
    auto name = Dict::getString(obj, "name");
    auto transform = Dict::getObject(obj, "result");
    if (name && transform) {
      _library[*name] = *transform;
    }
  }  
}

void Functions::loadFunctions() {

  _functions["if"] = bind(&If::create);
  _functions["true"] = bind(&True::create);
  _functions["dict"] = bind(&Dict::create);
  _functions["equal"] = bind(&Equal::create);
  _functions["getmember"] = bind(&GetMember::create);
  _functions["setmember"] = bind(&SetMember::create);
  _functions["string"] = bind(&String::create);
  _functions["select"] = bind(&Select::create);
  _functions["apply"] = bind(&Apply::create);
  _functions["cur"] = bind(&Cur::create);
  _functions["pass"] = bind(&Pass::create);
  _functions["quote"] = bind(&Quote::create);
  _functions["list"] = bind(&List::create);
  _functions["map"] = bind(&Map::create);
  _functions["filter"] = bind(&Filter::create);
  _functions["head"] = bind(&Head::create);
  _functions["tail"] = bind(&Tail::create);
  _functions["length"] = bind(&Length::create);

}

bool Functions::hasNative(const string &name) {
  return _functions.count(name) == 1;
}
bool Functions::hasLibrary(const string &name) {
  return _library.count(name) == 1;
}

fPtr Functions::getNative(const string &name) {
  return _functions[name]();
}

DictO Functions::getLibrary(const string &name) {
  return _library[name];
}
