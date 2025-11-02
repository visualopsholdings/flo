/*
  function.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_function
#define H_function

#include <rfl.hpp>

using namespace std;

namespace flo {

class Transform;
class State;

class Function;

typedef shared_ptr<Function> fPtr;

class Function
{
public:

    virtual optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure) = 0;

};

template <typename T>
class Func: public Function
{
public:

  optional<rfl::Generic> exec(Transform &transform, State *state, const rfl::Generic &closure) override;
  
  static fPtr create() {
    return fPtr(new T());
  }
  
};

} // flo

#endif // H_function
