/*
  filter.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_filter
#define H_filter

#include "../function.hpp"

namespace flo {

class Filter: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure);

  static fPtr create();
  
};

} // flo

#endif // H_filter
