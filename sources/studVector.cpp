//
// // Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
//
#include "studVector.hpp"

#include "student.hpp"

studVector::studVector(const std::string path) {
  if (path == "") {
    throw std::runtime_error{"path not provided"};
  }
  std::string jsonPath = path;

  // Student s;

  std::ifstream file{jsonPath};
  if (!file) {
    throw std::runtime_error{"unable to open json:  " + jsonPath};
  }

  json data;
  file >> data;

  if (!(data.at("items").is_array())) {
    throw std::runtime_error{"items are not an array" + jsonPath};
  }

  std::vector<Student> s = std::vector<Student>();
  size_t size = 0;
  for (json& student : data.at("items")) {
    Student d = Student(student);
    s.push_back(d);
    size++;
  }

  if (data.at("_meta").at("count") != size) {
    throw std::runtime_error{"_meta.count != len(items)"};
  }
  //  std::string b = "stringgg";
  //
  //  std::cout << "| name                          | group     | avg    | debt
  //  "
  //               "    |\n";
  //  for (auto i : s) {
  //    std::cout <<
  //    "|-------------------------------|-----------|--------|-------"
  //                 "------|\n";
  //    std::cout << '|';
  //    std::cout.width(31);
  //    std::cout.setf(std::ios::left);
  //    std::cout.fill(' ');
  //    std::cout << i.Name;
  //    std::cout << "| ";
  //    std::cout.width(10);
  //    std::cout.fill(' ');
  //    if (i.Group.type() == typeid(7)) {
  //      std::cout << std::any_cast<int>(i.Group);
  //    }
  //    if (i.Group.type() == typeid(b)) {
  //      std::cout << std::any_cast<std::string>(i.Group);
  //    }
  //    std::cout << "| ";
  //    std::cout.width(7);
  //    std::cout.fill(' ');
  //    std::cout.precision(2);
  //    std::cout << std::fixed << i.Avg;
  //    std::cout << "| ";
  //    std::cout.width(12);
  //    std::cout.fill(' ');
  //    if (i.Debt.type() == typeid(b)) {
  //      std::cout << std::any_cast<std::string>(i.Debt);
  //    } else if (i.Debt.type() == typeid(9)) {
  //      if (std::any_cast<int>(i.Debt) == 0) {
  //        std::cout << "null";
  //      }
  //    }
  //    std::cout << '|' << '\n';
  //  }
  //  std::cout <<
  //  "|-------------------------------|-----------|--------|---------"
  //               "----|\n";
  //  ;
}
void studVector::write(std::vector<Student> s) {
  std::string b = "stringgg";
  std::cout << "| name                          | group     | avg    | debt    "
               "    |\n";

  for (auto i : s) {
    std::cout << "|-------------------------------|-----------|--------|-------"
                 "------|\n";
    std::cout << '|';
    std::cout.width(31);
    std::cout.setf(std::ios::left);
    std::cout.fill(' ');
    std::cout << i.Name;
    std::cout << "| ";
    std::cout.width(10);
    std::cout.fill(' ');
    if (i.Group.type() == typeid(7)) {
      std::cout << std::any_cast<int>(i.Group);
    }
    if (i.Group.type() == typeid(b)) {
      std::cout << std::any_cast<std::string>(i.Group);
    }
    std::cout << "| ";
    std::cout.width(7);
    std::cout.fill(' ');
    std::cout.precision(2);
    std::cout << std::fixed << i.Avg;
    std::cout << "| ";
    std::cout.width(12);
    std::cout.fill(' ');
    if (i.Debt.type() == typeid(b)) {
      std::cout << std::any_cast<std::string>(i.Debt);
    } else if (i.Debt.type() == typeid(9)) {
      if (!i.Debt.has_value()) {
        std::cout << "null";
      }
    }
    std::cout << '|' << '\n';
  }
  std::cout << "|-------------------------------|-----------|--------|---------"
               "----|\n";
}
