/*
  reflect.hpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 12-Oct-2025
    
  https://github.com/visualopsholdings/flo
*/

#ifndef H_reflect
#define H_reflect

#include <rfl.hpp>
#include <optional>

class Reflect {

public:

  static std::optional<std::string> getString(std::optional<rfl::Object<rfl::Generic> > obj, const std::string &name);
  static std::optional<rfl::Object<rfl::Generic> > getObject(std::optional<rfl::Object<rfl::Generic> > obj, const std::string &name);
  static std::optional<rfl::Generic> getGeneric(std::optional<rfl::Object<rfl::Generic> > obj, const std::string &name);

  static std::optional<rfl::Object<rfl::Generic> > getObject(const rfl::Generic &obj);
  static std::optional<std::vector<rfl::Generic> > getVector(const rfl::Generic &obj);
  static std::optional<std::string> getString(const rfl::Generic &obj);
  static std::optional<long> getNum(const rfl::Generic &obj);
  static std::optional<bool> getBool(const rfl::Generic &obj);

};

#endif // H_reflect
