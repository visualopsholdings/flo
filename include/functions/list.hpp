/*
  list.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 25-Oct-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_list
#define H_list

#include "../function.hpp"

namespace flo {

class List: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_list
