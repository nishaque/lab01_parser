//
// // Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
//

#include "student.hpp"
//#include <nlohmann/json.hpp>
//#include <sstream>
//#include <typeinfo>
//#include <vector>
// using nlohmann::json;

Student::Student(const json &j) {
  if (j.size() == 0) {
    throw std::invalid_argument{"i"};
  }
  j.at("name").get_to(Name);

  if (j.at("group").is_string()) {
    std::string a = j.at("group");
    Group = a;
  } else {
    int a = j.at("group");
    Group = a;
  }

  j.at("avg").get_to(Avg);

  if (j.at("debt").is_array()) {
    std::vector<std::string> d;
    for (auto t : j.at("debt")) {
      d.push_back(t);
    }
    Debt = d;
  }
  if (j.at("debt").is_string()) {
    std::string a = j.at("debt");
    Debt = a;
  }
}
// void Student::Table(){
