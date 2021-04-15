#include <iostream>
#include "employee.hpp"

using namespace std;

void Person::Display() const{
  cout << "Just a regular guy" << endl
    << f_name << " " << l_name << endl
    << age << " y.o" << endl
    << endl;
}

void Employee::Display() const{
  cout << "Job type: Employee" << endl
    << "ID: " << id << endl
    << f_name << " " << l_name << endl
    << age << " y.o" << endl
    << "Salary: " << salary << " $" << endl
    << "Departament: " << department << endl
    << endl;
}

void Manager::Display() const{
  cout << "Job type: Manager" << endl
    << "ID: " << id << endl
    << f_name << " " << l_name << endl
    << "Age: "  << age << " y.o" << endl
    << "Salary: " << salary << " $" << endl
    << "Departament: " << department << endl
    << "Subbordinates:" << endl;
    DisplaySubordinates();
}

void Manager::DisplaySubordinates() const{

  for(const auto e : subordinates)
  {
    cout << "    ";
    e->Display();
  }
  cout << endl;
}

bool Manager::AddSubordinate(Person* p){
  if(p)
  {
    subordinates.push_back(p);
    return true;
  }
  return false;
}