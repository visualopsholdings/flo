/*
  processor.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 27-May-2024
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_processor
#define H_processor

#include <istream>
#include <rfl.hpp>

using namespace std;

namespace flo {

class Functions;

class Processor
{
public:
  Processor(istream &infile, Functions &functions);
  Processor(const rfl::Generic &json, Functions &functions);
  Processor(Functions &functions);
  
  optional<rfl::Generic> transform(istream &transform);
  optional<rfl::Generic> transform(const rfl::Generic &jt);
 
  static void pretty_print( ostream& os, rfl::Generic const& jv);
 
private:
  Functions &_functions;
  rfl::Generic _json;
  
};

} // flo

#endif // H_processor
