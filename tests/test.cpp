// Copyright 2020 Timoshenko Yulia timoshenkojulie01@gmail.com
#include <gtest/gtest.h>

#include "studVector.hpp"
#include "student.hpp"

TEST(stV, CorrectNullFieldType) {
  Student s{json::parse(R"({
      "name": "Ivanov Petr",
      "group": "1",
      "avg": 4.25,
      "debt": null
    })")};
  ASSERT_EQ(s.Name, "Ivanov Petr");
  ASSERT_EQ(std::any_cast<std::string>(s.Group), "1");
  ASSERT_DOUBLE_EQ(s.Avg, 4.25);
  ASSERT_FALSE(s.Debt.has_value());
}



TEST(stV, CorrectArFieldT) {
  Student s{json::parse(R"({
      "name": "Pertov Nikita",
      "group": "IU8-31",
      "avg": 3.33,
      "debt": [
        "C++",
        "Linux",
        "Network"
      ]
    })")};
  ASSERT_EQ(s.Name, "Pertov Nikita");
  ASSERT_EQ(std::any_cast<std::string>(s.Group), "IU8-31");
  ASSERT_DOUBLE_EQ(s.Avg, 3.33);
  ASSERT_EQ(std::any_cast<std::vector<std::string>>(s.Debt).size(), 3);
}
TEST(stV, CorrectException) {
  ASSERT_THROW(Student{json::parse(R"({})")}, std::invalid_argument);
}
TEST (stVect, Path){
  ASSERT_THROW(studVector("f"), std::runtime_error);
}

TEST (stVect, NoPath){
  ASSERT_THROW(studVector(""), std::runtime_error);
}

//TEST(stVect, NotArray) {
//  Student s{json::parse(R"({
//      "name": "Pertov Nikita",
//      "group": "IU8-31",
//      "avg": 3.33,
//      "debt": [
//        "C++",
//        "Linux",
//        "Network"
//      ]
//    })")};
//}

TEST(stV, BasicParse) {
  Student s(json::parse(R"({
      "name": "Sidorov Ivan",
      "group": 31,
      "avg": 4,
      "debt": "C++"
    })"));
  ASSERT_EQ(s.Name, "Sidorov Ivan");
  ASSERT_EQ(std::any_cast<int>(s.Group), 31);
  ASSERT_DOUBLE_EQ(s.Avg, 4.00);
  ASSERT_EQ(std::any_cast<std::string>(s.Debt), "C++");
}
