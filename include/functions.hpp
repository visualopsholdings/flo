/*
  functions.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_functions
#define H_functions

#include "function.hpp"
#include "dict.hpp"

#include <map>

using namespace std;
using vops::DictG;
using vops::DictO;

namespace flo {

typedef function<fPtr ()> fnHandler;

class Functions
{
public:
    Functions(const DictG &transform);
    
    bool hasNative(const string &name);
    bool hasLibrary(const string &name);
    fPtr getNative(const string &name);
    DictO getLibrary(const string &name);
    
private:
  map<string, fnHandler> _functions;
  map<string, DictO> _library;
  
  void loadFunctions();
  
};

} // flo

#endif // H_functions
