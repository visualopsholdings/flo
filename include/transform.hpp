/*
  transform.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_transform
#define H_transform

#include "dict.hpp"

using namespace std;
using vops::DictG;

namespace vops {
namespace flo {

class State;
class Functions;

class Transform
{
public:
  Transform(Functions &functions);
  
  optional<DictG> exec(const DictG &func, State *state);

  DictG error(const string &msg) const;

private:
  Functions &_functions;
  
};

} // flo
} // vops

#endif // H_transform
