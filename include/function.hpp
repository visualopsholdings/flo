/*
  function.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_function
#define H_function

#include <boost/json.hpp>

using namespace std;
using json = boost::json::value;

class Transform;
class State;

class Function;

typedef shared_ptr<Function> fPtr;

class Function
{
public:

    virtual optional<json> exec(Transform &transform, State *state, json &closure) = 0;

};

#endif // H_function
