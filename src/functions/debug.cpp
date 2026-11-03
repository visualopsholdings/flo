/*
  debug.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 3-Nov-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "control.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"
#include "date.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace vops::flo;

template<>
optional<DictG> Func<Debug>::exec(Transform &transform, State *state, const DictG &closure) {
  
  cout << "--debug--" << endl;
  cout << Dict::toString(closure) << endl;
  cout << "---------" << endl;

  return closure;
         
}
