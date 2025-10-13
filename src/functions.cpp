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

using namespace flo;

Functions::Functions() {

  _functions["null"] = bind(&Null::create);
  _functions["if"] = bind(&If::create);
  _functions["true"] = bind(&True::create);
  _functions["dict"] = bind(&Dict::create);
  _functions["equal"] = bind(&Equal::create);
  _functions["getmember"] = bind(&GetMember::create);
  _functions["setmember"] = bind(&SetMember::create);
  _functions["string"] = bind(&String::create);
  _functions["select"] = bind(&Select::create);
  
}

bool Functions::has(const string &name) {
  return _functions.count(name) == 1;
}

fPtr Functions::get(const string &name) {
  return _functions[name]();
}
