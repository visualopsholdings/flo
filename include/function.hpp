/*
  function.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
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

    virtual optional<rfl::Generic> exec(Transform &transform, State *state, rfl::Generic &closure) = 0;

};

} // flo

#endif // H_function
