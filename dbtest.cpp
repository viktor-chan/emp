#include <iostream>

#include "db.h"

using namespace std;
using namespace Records;

int main() {
  db myDB;
  em &emp1 = myDB.addEmployee("Greg", "Wallis");
  emp1.fire();

  em &emp2 = myDB.addEmployee("Marc", "White");
  emp2.setSalary(100000);

  em &emp3 = myDB.addEmployee("John", "Doe");
  emp3.setSalary(10000);
  emp3.promote();

  cout << "all employees: " << endl << endl;
  myDB.displayAll();

  cout << endl << "current employees: " << endl << endl;
  myDB.displayCurrent();

  cout << endl << "former employees: " << endl << endl;
  myDB.displayFormer();

  cout << endl << "Try to find someone: " << endl << endl;
  em &emp4 = myDB.getEmployee("Marc", "White");

  emp4.display();
}
