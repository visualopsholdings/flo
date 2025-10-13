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

namespace flo {

typedef function<shared_ptr<Function> ()> fnHandler;

class Functions
{
public:
    Functions();
    Functions(const std::vector<rfl::Generic> &library);
    
    bool hasNative(const string &name);
    bool hasLibrary(const string &name);
    fPtr getNative(const string &name);
    rfl::Object<rfl::Generic> getLibrary(const string &name);
    
private:
  map<string, fnHandler> _functions;
  map<string, rfl::Object<rfl::Generic> > _library;
  
  void loadFunctions();
  
};

} // flo

#endif // H_functions
