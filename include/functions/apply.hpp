/*
  apply.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 14-Oct-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_apply
#define H_apply

#include "../function.hpp"

namespace flo {

class Apply: public Function
{
public:
  
  // Function
  virtual optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure);

  static fPtr create();
  
private:

  optional<rfl::Generic> apply(Transform &transform, State *state, const rfl::Generic &closure);

};

} // flo

#endif // H_apply
