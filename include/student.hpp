//
// Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
//

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_
#include <any>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <typeindex>
#include <vector>

using nlohmann::json;

struct Student {
  std::string Name;
  std::any Group;
  double Avg;
  std::any Debt;

  Student() {}
  explicit Student(const json& j);
};

#endif  // INCLUDE_STUDENT_HPP_
