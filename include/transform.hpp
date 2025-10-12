/*
  transform.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_transform
#define H_transform

#include <rfl.hpp>

using namespace std;

class State;
class Functions;

class Transform
{
public:
  Transform(Functions &functions);
  
  optional<rfl::Generic> exec(rfl::Generic &closure, State *state);

  rfl::Generic error(const string &msg) const;

private:
  Functions &_functions;
  
};

#endif // H_transform
