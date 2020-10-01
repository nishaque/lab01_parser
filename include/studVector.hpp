//
// // Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
//

#ifndef INCLUDE_STUDVECTOR_HPP_
#define INCLUDE_STUDVECTOR_HPP_

#include "student.hpp"
#include <string>
#include <vector>
struct studVector {
  std::vector<Student> st;
  explicit studVector(const std::string path);
  void write(std::vector<Student> s);
};

#endif  // INCLUDE_STUDVECTOR_HPP_
