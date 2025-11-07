/*
  state.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_state
#define H_state

#include "dict.hpp"

using namespace std;
using vops::DictG;
using vops::DictV;

namespace vops {
namespace flo {

class State
{
public:
  State();
  State(const State &state);
  
  void set(const DictG &g);
    // set the element or collection based on the type of data.
    
  void setElem(const DictG &elem);
  void clearElem();
  bool hasElem() const;
  const DictG getElem() const;
  
  void setColl(const DictV &coll);
  void clearColl();
  bool hasColl() const;
  const DictV getColl() const;

private:
  
  optional<DictG> _elem;
  optional<DictV> _coll;
  
};

} // flo
} // vops

#endif // H_state
