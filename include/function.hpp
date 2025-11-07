/*
  function.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_function
#define H_function

#include "dict.hpp"

using namespace std;
using vops::DictG;

namespace flo {

class Transform;
class State;

class Function;

typedef shared_ptr<Function> fPtr;

class Function
{
public:

    virtual optional<DictG> exec(Transform &transform, State *state, const DictG &closure) = 0;

};

template <typename T>
class Func: public Function
{
public:

  optional<DictG> exec(Transform &transform, State *state, const DictG &closure) override;
  
  static fPtr create() {
    return fPtr(new T());
  }
  
};

} // flo

#endif // H_function
