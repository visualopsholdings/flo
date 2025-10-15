/*
  functions.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#include "functions.hpp"

#include "functions/null.hpp"
#include "functions/if.hpp"
#include "functions/true.hpp"
#include "functions/dict.hpp"
#include "functions/equal.hpp"
#include "functions/getmember.hpp"
#include "functions/setmember.hpp"
#include "functions/string.hpp"
#include "functions/select.hpp"
#include "functions/apply.hpp"
#include "functions/cur.hpp"
#include "functions/pass.hpp"
#include "generic.hpp"

using namespace flo;

Functions::Functions() {

  loadFunctions();
  
}

Functions::Functions(const std::vector<rfl::Generic> &library) {

  loadFunctions();

  for (auto i: library) {
    auto obj = Generic::getObject(i);
    auto name = Generic::getString(obj, "name");
    auto transform = Generic::getObject(obj, "result");
    if (name && transform) {
      _library[*name] = *transform;
    }
  }  
}

void Functions::loadFunctions() {

  _functions["null"] = bind(&Null::create);
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

rfl::Object<rfl::Generic> Functions::getLibrary(const string &name) {
  return _library[name];
}
