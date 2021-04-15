#include <iostream>
#include "employee.hpp"

using namespace std;

void Person::Display() const{
  cout 
    << "------------------------------"
    << "Just a regular guy" << endl
    << f_name << " " << l_name << endl
    << age << " y.o" << endl
    << "------------------------------"
    << endl;
}

void Employee::Display() const{
  cout 
    << "------------------------------" << endl
    << "Job type: Employee" << endl
    << "ID: " << id << endl
    << f_name << " " << l_name << endl
    << age << " y.o" << endl
    << "Salary: " << salary << "$" << endl
    << "Departament: " << department << endl
    << "------------------------------"
    << endl;
}

void Manager::Display() const{
  cout
    << "------------------------------" << endl
    << "Job type: Manager" << endl
    << "ID: " << id << endl
    << f_name << " " << l_name << endl
    << "Age: "  << age << " y.o" << endl
    << "Salary: " << salary << "$" << endl
    << "Departament: " << department << endl
    << "Subbordinates:" << endl
    << "{" << endl;
    DisplaySubordinates();
    cout << "}" << endl
    << "------------------------------"
    << endl;
}

void Manager::DisplaySubordinates() const{
  if (!subordinates.size())
    cout << "none" << endl;
  for(const auto e : subordinates)
    e->Display();
}

bool Manager::AddSubordinate(Person* p){
  if(p)
  {
    subordinates.push_back(p);
    return true;
  }
  return false;
}

Manager::Manager(const Manager& other) {
  *this = other;
}

Manager& Manager::operator = (const Manager& other) {
  f_name = other.f_name;
  l_name = other.l_name;
  age = other.age;
  department = other.department;
  salary = other.salary;
  id = other.id;

  for (const auto person : other.subordinates) {
    subordinates.push_back(person);
  }
  return *this;
}