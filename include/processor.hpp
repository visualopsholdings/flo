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
#include "dict.hpp"

using namespace std;
using vops::DictG;

namespace flo {

class Functions;

class Processor
{
public:
  Processor(Functions &functions): _functions(functions) {}
  
  optional<DictG> transform(const DictG &code, std::optional<DictG> input=nullopt);
  optional<DictG> transform(const DictG &code, const std::string &scenario);

  static optional<DictG> getFirstScenarioInput(const DictG &code);
  
private:
  Functions &_functions;
  
};

} // flo

#endif // H_processor
