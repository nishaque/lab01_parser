//
// // Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
//

#ifndef INCLUDE_STUDVECTOR_HPP_
#define INCLUDE_STUDVECTOR_HPP_

#include <string>
#include <vector>

#include "student.hpp"
struct studVector {
  std::vector<Student> st = std::vector<Student>();
  explicit studVector(const std::string&);
  explicit studVector(json&);
  void fromJsonAr(json);
  void write();
};

#endif  // INCLUDE_STUDVECTOR_HPP_
