#include "em.h"
#include <iostream>

using namespace std;

namespace Records {
em::em(const std::string &firstName, const std::string &lastName)
    : mFirstName(firstName), mLastName(lastName) {}

void em::promote(int raiseAmount) { setSalary(getSalary() + raiseAmount); }

void em::demote(int demeritAmount) { setSalary(getSalary() - demeritAmount); }

void em::hire() { mHired = true; }

void em::fire() { mHired = false; }

void em::display() const {
  cout << "em: " << getLastName() << ", " << getFirstName() << endl;
  cout << "-------------------------" << endl;
  cout << (isHired() ? "Current em" : "Former em") << endl;
  cout << "em Number: " << getEmployeeNumber() << endl;
  cout << "Salary: $" << getSalary() << endl;
  cout << endl;
}

void em::setFirstName(const string &firstName) { mFirstName = firstName; }

const string &em::getFirstName() const { return mFirstName; }

void em::setLastName(const string &lastName) { mLastName = lastName; }

const string &em::getLastName() const { return mLastName; }

void em::setEmployeeNumber(int employeeNumber) {
  mEmployeeNumber = employeeNumber;
}

int em::getEmployeeNumber() const { return mEmployeeNumber; }

void em::setSalary(int newSalary) { mSalary = newSalary; }

int em::getSalary() const { return mSalary; }

bool em::isHired() const { return mHired; }
} // namespace Records
