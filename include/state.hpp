/*
  state.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_state
#define H_state

#include <boost/json.hpp>
#include <optional>

using namespace std;
using json = boost::json::value;

class State
{
public:
  State();
  State(const State &state);
  
//   int arity() const;
//   
//   void setColl(json *coll);
//   bool hasColl() const;
//   const json &coll() const;
// 
//   void setElem(json *elem);
//   bool hasElem() const;
//   const json &elem() const;
  
private:
  
//   json *_coll;
//   json *_elem;
  
};

#endif // H_state
