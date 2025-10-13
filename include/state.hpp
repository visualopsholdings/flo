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
  
  void setElem(rfl::Object<rfl::Generic> &elem);
  bool hasElem() const;
  const rfl::Object<rfl::Generic> getElem() const;
  
private:
  
  optional<rfl::Object<rfl::Generic>> _elem;
  
};

} // flo

#endif // H_state
