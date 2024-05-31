/*
  state.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_state
#define H_state

#include <boost/json.hpp>

using namespace std;

class State
{
public:
  State();
  State(const State &state);
  
  void setElem(boost::json::object &elem);
  bool hasElem() const;
  const boost::json::object getElem() const;
  
private:
  
  optional<boost::json::object> _elem;
  
};

#endif // H_state
