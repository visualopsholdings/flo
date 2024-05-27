/*
  method.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_method
#define H_method

#include "function.hpp"

#include <boost/json.hpp>

using namespace std;
using json = boost::json::value;

class Method
{
public:
  Method(fPtr func, json closure);
  
  json call(const Transform &transform, State *state, json closure);
   
private:
  json _closure;
  fPtr _func;
  
};

#endif // H_method
