/*
  list.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 25-Oct-2025
  
  "List" category functions as specified in docs.json.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_listfun
#define H_listfun

#include "function.hpp"

namespace flo {

class List: public Func<List> {
};

class Map: public Func<Map> {
};

class Filter: public Func<Filter> {
};

class Length: public Func<Length> {
};

class Head: public Func<Head> {
};

class Tail: public Func<Tail> {
};

class Dict: public Func<Dict> {
};

} // flo

#endif // H_listfun
