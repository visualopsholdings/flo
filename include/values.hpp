/*
  values.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 2-Nov-2025
  
  "Values" category functions as specified in docs.json.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_values
#define H_values

#include "function.hpp"

namespace vops {
namespace flo {

class True: public Func<True> {
};

class Cur: public Func<Cur> {
};

class String: public Func<String> {
};

class StringCat: public Func<StringCat> {
};

} // flo
} // vops

#endif // H_values
