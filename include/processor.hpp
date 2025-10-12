/*
  processor.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  https://github.com/visualopsholdings/flo
*/

#ifndef H_processor
#define H_processor

#include <istream>
#include <rfl.hpp>

using namespace std;

class Functions;

class Processor
{
public:
  Processor(istream &infile, Functions &functions);
  Processor(rfl::Generic &json, Functions &functions);
  
  optional<rfl::Generic> transform(istream &transform);
  optional<rfl::Generic> transform(rfl::Generic &jt);
 
  static void pretty_print( ostream& os, rfl::Generic const& jv);
 
private:
  Functions &_functions;
  rfl::Generic _json;
  
};

#endif // H_processor
