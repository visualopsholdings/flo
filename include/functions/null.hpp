/*
  null.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 28-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_null
#define H_null

#include "../function.hpp"

namespace flo {

class Null: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_null
