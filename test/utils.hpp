/*
  utils.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 1-Nov-2025
  
  Test utilities.
  
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_utils
#define H_utils

#include <string>
#include <optional>
#include <rfl.hpp>

class Utils
{
public:

  static std::optional<rfl::Object<rfl::Generic> > loadYML(const std::string &fn);
  static std::optional<rfl::Object<rfl::Generic> > loadJSON(const std::string &fn);

};

#endif // H_utils
