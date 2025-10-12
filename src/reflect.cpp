/*
  reflect.cpp
  
  Author: Paul Hamilton (paul@visualops.com)
  Date: 12-Oct-2025
    
  https://github.com/visualopsholdings/flo
*/

#include "reflect.hpp"

#include <rfl.hpp>
#include <rfl/json.hpp>

using namespace std;

std::optional<std::string> Reflect::getString(std::optional<rfl::Object<rfl::Generic> > obj, const std::string &name) {

  if (!obj) {
    return nullopt;
  }
  
  auto prop = obj->get(name);
  if (!prop) {
    return nullopt;
  }
  
  return getString(*prop);
  
}

std::optional<rfl::Object<rfl::Generic> > Reflect::getObject(std::optional<rfl::Object<rfl::Generic> > obj, const std::string &name) {

  if (!obj) {
    return nullopt;
  }
  
  auto d = getObject(*obj);
  if (!d) {
    return nullopt;
  }
  
  auto prop = d->get(name);
  if (!prop) {
    return nullopt;
  }
  
  return getObject(*prop);
  
}

std::optional<rfl::Generic> Reflect::getGeneric(std::optional<rfl::Object<rfl::Generic> > obj, const std::string &name) {

  if (!obj) {
    return nullopt;
  }
  
  auto d = getObject(*obj);
  if (!d) {
    return nullopt;
  }
  
  auto prop = d->get(name);
  if (!prop) {
    return nullopt;
  }
  
  return *prop;
  
}

optional<rfl::Object<rfl::Generic> > Reflect::getObject(const rfl::Generic &obj) {

  optional<rfl::Object<rfl::Generic> > dict;
  std::visit([&obj, &dict](const auto &field) {
  
    if constexpr (is_same<decay_t<decltype(field)>, rfl::Object<rfl::Generic> >()) {
      dict = field;
    }

  }, obj.variant());

  return dict;
  
}

optional<vector<rfl::Generic> > Reflect::getVector(const rfl::Generic &obj) {

  optional<vector<rfl::Generic> > v;
  std::visit([&obj, &v](const auto &field) {
  
    if constexpr (is_same<decay_t<decltype(field)>, vector<rfl::Generic> >()) {
      v = field;
    }

  }, obj.variant());

  return v;
  
}

optional<string> Reflect::getString(const rfl::Generic &obj) {

  optional<string> str;
  std::visit([&obj, &str](const auto &field) {
  
    if constexpr (is_same<decay_t<decltype(field)>, string>()) {
      str = field;
    }

  }, obj.variant());

  return str;
  
}

optional<long> Reflect::getNum(const rfl::Generic &obj) {

  optional<long> i;
  std::visit([&obj, &i](const auto &field) {
  
    if constexpr (is_same<decay_t<decltype(field)>, long>() || is_same<decay_t<decltype(field)>, long long>()) {
      i = field;
    }
  }, obj.variant());

  return i;
  
}

optional<bool> Reflect::getBool(const rfl::Generic &obj) {

  optional<bool> b;
  std::visit([&obj, &b](const auto &field) {
  
    if constexpr (is_same<decay_t<decltype(field)>, bool>()) {
      b = field;
    }
  }, obj.variant());

  return b;
  
}
