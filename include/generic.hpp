/*
  generic.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 12-Oct-2025
    
  helpers for cppreflect.
    
  Licensed under [version 3 of the GNU General Public License] contained in LICENSE.
 
  https://github.com/visualopsholdings/flo
*/

#ifndef H_generic
#define H_generic

#include <rfl.hpp>
#include <optional>

namespace flo {

class Generic {

public:

  static std::optional<rfl::Object<rfl::Generic> > getObject(const rfl::Generic &obj);
    // given a generic object, get an Object out of it.
    
  static std::optional<std::string> getString(const rfl::Generic &obj);
    // given a generic object, get a string out of it.
    
  static std::optional<long> getNum(const rfl::Generic &obj);
    // given a generic object, get a long out of it.
    
  static std::optional<bool> getBool(const rfl::Generic &obj);
    // given a generic object, get a boolean out of it.
    
  static bool isVector(const rfl::Generic &obj);
    // Return true IF this is a vector.

  static std::optional<std::vector<rfl::Generic> > getVector(const rfl::Generic &obj);
    // given a generic object, get a vector out of it.

  static std::optional<rfl::Object<rfl::Generic> > getObject(std::optional<rfl::Object<rfl::Generic> > dict, const std::string &name);
    // get an object out of the dictionary with the property name.
    // This is chainable.
    
  static std::optional<rfl::Generic> getGeneric(std::optional<rfl::Object<rfl::Generic> > dict, const std::string &name);
    // get a generic out of the dictionary with the property name.
    // This is chainable.
    
  static std::optional<std::string> getString(std::optional<rfl::Object<rfl::Generic> > dict, const std::string &name);
    // get a string out of the dictionary with the property name.
    // This is chainable.
    
  static std::optional<long> getNum(std::optional<rfl::Object<rfl::Generic> > dict, const std::string &name);
    // get a long out of the dictionary with the property name.
    // This is chainable.
    
  static std::optional<bool> getBool(std::optional<rfl::Object<rfl::Generic> > dict, const std::string &name);
    // get a bool out of the dictionary with the property name.
    // This is chainable.
    
  static std::optional<std::vector<rfl::Generic> > getVector(std::optional<rfl::Object<rfl::Generic> > dict, const std::string &name);
    // get a string out of the dictionary with the property name.
    // This is chainable.

  static std::string toString(const rfl::Generic &g, const std::string &format=".json");
    // dump the generic out as JSON or YML.

  static std::optional<rfl::Generic> parseStream(std::istream &s, const std::string &format=".json");
    // given a stream, and a format the stream is in (.json, .yml) parse it.

};

} // flo

#endif // H_generic
