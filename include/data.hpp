/*
  data.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 2-Nov-2025
  
  "Data" category functions as specified in docs.json.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_data
#define H_data

#include "function.hpp"

namespace vops {
namespace flo {

class SetMember: public Func<SetMember> {
};

class GetMember: public Func<GetMember> {
};

} // flo
} // vops

#endif // H_data
