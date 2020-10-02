//
// // Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
//
#include "studVector.hpp"

#include "student.hpp"

studVector::studVector(const std::string& path) {
  if (path.empty()) {
    throw std::runtime_error{"path not provided"};
  }

  std::ifstream file{path};

  if (!file) {
    throw std::runtime_error{"unable to open json:  " + path};
  }
  json data = "";
  file >> data;
  fromJsonAr(data);
}
void studVector::fromJsonAr(json data) {
  if (!(data.at("items").is_array()))
    throw std::runtime_error{"items are not an array"};

  size_t size = 0;
  for (json& student : data.at("items")) {
    Student d = Student(student);
    st.push_back(d);
    size++;
  }

  if (data.at("_meta").at("count") != size) {
    throw std::runtime_error{"_meta.count != len(items)"};
  }

  write();
}
void studVector::write() {
  std::string b = "stringgg";
  std::cout << "| name                          | group     | avg    | debt    "
               "    |\n";

  for (auto i : st) {
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
    if (i.Debt.type() == typeid(b)) {
      std::cout.width(12);
      std::cout.fill(' ');
      std::cout << std::any_cast<std::string>(i.Debt);
    } else if (!i.Debt.has_value()) {
      std::cout.width(12);
      std::cout.fill(' ');
      std::cout << "null";
    } else {
      std::cout.width(2);
      std::cout.fill(' ');
      std::cout << std::any_cast<std::vector<std::string>>(i.Debt).size();
      std::cout.width(10);
      std::cout.fill(' ');
      std::cout << "items";
    }
    std::cout << '|' << '\n';
  }
  std::cout << "|-------------------------------|-----------|--------|---------"
               "----|\n";
}

studVector::studVector(json& data) { fromJsonAr(data); }
