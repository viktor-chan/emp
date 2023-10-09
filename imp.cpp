#include "db.h"
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace Records;

int displayMenu();
void doHire(db &mydb);
void doFire(db &mydb);
void doPromote(db &mydb);
void doDemote(db &mydb);

int main() {
  db employeeDB;
  bool done = false;
  while (!done) {
    int selection = displayMenu();
    switch (selection) {
    case 0:
      done = true;
      break;
    case 1:
      doHire(employeeDB);
      employeeDB.displayAll();
      break;
    case 2:
      doFire(employeeDB);
      break;
    case 3:
      doPromote(employeeDB);
      break;
    case 4:
      employeeDB.displayAll();
      break;
    case 5:
      employeeDB.displayCurrent();
      break;
    case 6:
      employeeDB.displayFormer();
      break;
    default:
      cerr << "Unknown command." << endl;
      break;
    }
  }
  return 0;
}

int displayMenu() {
  int selection;
  cout << endl;
  cout << "em Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Hire a new employee" << endl;
  cout << "2) Fire an employee" << endl;
  cout << "3) Promote an employee" << endl;
  cout << "4) List all employees" << endl;
  cout << "5) List all current employees" << endl;
  cout << "6) List all former employees" << endl;
  cout << "0) Quit" << endl;
  cin >> selection;
  return selection;
}

void doHire(db &mydb) {
  string firstName;
  string lastName;

  cout << "First name? ";
  cin >> firstName;

  cout << "Last name? ";
  cin >> lastName;

  mydb.addEmployee(firstName, lastName);
}

void doFire(db &mydb) {
  int employeeNumber;
  cout << "em number? ";
  cin >> employeeNumber;

  try {
    em &emp = mydb.getEmployee(employeeNumber);
    emp.fire();
    cout << "em " << employeeNumber << " terminated." << endl;
  } catch (const std::logic_error &exception) {
    cerr << "Unable to terminate employee: " << exception.what() << endl;
  }
}

void doPromote(db &mydb) {
  int employeeNumber;
  int raiseAmount;
  cout << "em number? ";
  cin >> employeeNumber;

  cout << "How much of a raise? ";
  cin >> raiseAmount;

  try {
    em &emp = mydb.getEmployee(employeeNumber);
    emp.promote(raiseAmount);
  } catch (const std::logic_error &exception) {
    cerr << "Unable to promote employee: " << exception.what() << endl;
  }
}
