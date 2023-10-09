#include "db.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace Records {
em &db::addEmployee(const string &firstName, const string &lastName) {
  em theEmployee(firstName, lastName);
  theEmployee.setEmployeeNumber(mNextEmployeeNumber++);
  theEmployee.hire();
  mEmployees.push_back(theEmployee);
  return mEmployees[mEmployees.size() - 1];
}

em &db::getEmployee(int employeeNumber) {
  for (auto &employee : mEmployees) {
    if (employee.getEmployeeNumber() == employeeNumber) {
      return employee;
    }
  }
  throw logic_error("No employee found.");
}
em &db::getEmployee(const string &firstName, const string &lastName) {
  for (auto &employee : mEmployees) {
    if (employee.getFirstName() == firstName &&
        employee.getLastName() == lastName) {
      return employee;
    }
  }
  throw logic_error("No employee found.");
}

void db::displayAll() const {
  for (const auto &employee : mEmployees) {
    employee.display();
  }
}

void db::displayCurrent() const {
  for (const auto &employee : mEmployees) {
    if (employee.isHired())
      employee.display();
  }
}

void db::displayFormer() const {
  for (const auto &employee : mEmployees) {
    if (!employee.isHired())
      employee.display();
  }
}
} // namespace Records
