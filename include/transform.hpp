/*
  transform.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_transform
#define H_transform

#include <boost/json.hpp>

using namespace std;
using json = boost::json::value;

class State;
class Functions;

class Transform
{
public:
  Transform(json &json, Functions &functions);
  
  optional<json> exec(json &closure, State *state);

  json &getJson();
  
  json error(const string &msg) const;

private:
  Functions &_functions;
  json &_json; // the JSON we are transforming.
  
};

#endif // H_transform
