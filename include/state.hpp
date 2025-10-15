/*
  state.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_state
#define H_state

#include <rfl.hpp>

using namespace std;

namespace flo {

class State
{
public:
  State();
  State(const State &state);
  
  void setElem(const rfl::Generic &elem);
  void clearElem();
  bool hasElem() const;
  const rfl::Generic getElem() const;
  
  void setColl(const std::vector<rfl::Generic> &coll);
  void clearColl();
  bool hasColl() const;
  const std::vector<rfl::Generic> getColl() const;

private:
  
  optional<rfl::Generic> _elem;
  optional<std::vector<rfl::Generic> > _coll;
  
};

} // flo

#endif // H_state
