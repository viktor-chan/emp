#pragma once
#include "em.h"
#include <iostream>
#include <vector>

namespace Records {
const int kFirstEmployeeNumber = 1000;
class db {
public:
  em &addEmployee(const std::string &firstName, const std::string &lastName);
  em &getEmployee(int employeeNumber);
  em &getEmployee(const std::string &firstName, const std::string &lastName);

  void displayAll() const;
  void displayCurrent() const;
  void displayFormer() const;

private:
  std::vector<em> mEmployees;
  int mNextEmployeeNumber = kFirstEmployeeNumber;
};
} // namespace Records
