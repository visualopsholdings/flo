/*
  select.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 31-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_select
#define H_select

#include "../function.hpp"

namespace flo {

class Select: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_select
