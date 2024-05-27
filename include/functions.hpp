/*
  functions.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_functions
#define H_functions

#include "function.hpp"

#include <map>

using namespace std;

typedef function<shared_ptr<Function> ()> fnHandler;

class Functions
{
public:
    Functions();
    
private:
  map<string, fnHandler> _functions;
  
};

#endif // H_functions
