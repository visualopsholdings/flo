/*
  control.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 2-Nov-2025
  
  "Control" category functions as specified in docs.json.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_control
#define H_control

#include "function.hpp"

namespace flo {

class If: public Func<If> {
};

class Apply: public Func<Apply> {
};

class Pass: public Func<Pass> {
};

class Select: public Func<Select> {
};

class Equal: public Func<Equal> {
};

class Quote: public Func<Quote> {
};

} // flo

#endif // H_control
