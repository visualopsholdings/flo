/*
  quote.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_quote
#define H_quote

#include "../function.hpp"

namespace flo {

class Quote: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_quote
