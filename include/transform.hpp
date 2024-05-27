/*
  transform.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_transform
#define H_transform

#include "method.hpp"

#include <boost/json.hpp>

using namespace std;
using json = boost::json::value;

class State;

class Transform
{
public:
  Transform(json &json);
  
  optional<json> get_value(State *state, json closure) const;
  
  optional<json> exec(json closure, State *state) const;

  Method get_method(json closure, State *state) const;

private:
  json _json;
  
};

#endif // H_transform
