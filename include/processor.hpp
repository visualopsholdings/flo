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
  Processor(Functions &functions): _functions(functions) {}
  
  optional<rfl::Generic> transform(const rfl::Generic &code, std::optional<rfl::Generic> input=nullopt);
  optional<rfl::Generic> transform(const rfl::Generic &code, const std::string &scenario);

  static optional<rfl::Generic> getFirstScenarioInput(const rfl::Generic &code);
  
private:
  Functions &_functions;
  
};

} // flo

#endif // H_processor
