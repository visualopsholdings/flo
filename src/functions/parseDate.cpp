/*
  parseDate.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 2-Nov-2026
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#include "datefun.hpp"
#include "transform.hpp"
#include "state.hpp"
#include "dict.hpp"
#include "date.hpp"

#include <boost/log/trivial.hpp>

using namespace std;
using namespace vops::flo;

template<>
optional<DictG> Func<ParseDate>::exec(Transform &transform, State *state, const DictG &closure) {
  
//  BOOST_LOG_TRIVIAL(trace) << "convertDate " << Dict::toString(closure);

  auto format = Dict::getStringG(closure, "format");
  if (!format) {
    BOOST_LOG_TRIVIAL(error) << "missing format";
    return 0;
  }
  auto v = Dict::getObjectG(closure, "value");
  if (!v) {
    BOOST_LOG_TRIVIAL(error) << "missing value";
    return 0;
  }
  auto value = transform.exec(*v, state);
  if (!value) {
    return 0;
  }
  auto s = Dict::getString(*value);
  if (!s) {
    BOOST_LOG_TRIVIAL(error) << "value returned not a string";
  }
  std::tm tm{};
  std::istringstream iss(*s);
  iss >> std::get_time(&tm, format->c_str());
  std::ostringstream oss;
  oss << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S.000+00:00");

  return oss.str();
         
}
