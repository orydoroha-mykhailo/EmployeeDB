#include "database.hpp"
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

bool Database::LoadFromFile(const string& filename)
{
  string f_name, l_name, department;
  size_t id, age, salary;
  bool is_manager;

  ifstream csv(filename, ios::out);
  while (csv)
  {
    csv >> is_manager;

    char _;
    csv >> _ >> id >> _;
    getline(csv, f_name, ',');
    getline(csv, l_name, ',');
    csv >> age >> _;
    getline(csv, department, ',');
    csv >> salary;
    Person *p;
    switch (is_manager) {
    case false:
      p = new Employee(f_name, l_name, age, id);
      static_cast<Employee*>(p)->SetDepartment(department);
      static_cast<Employee*>(p)->SetSalary(salary);
      break;

    case true:
      new Manager;
      p = new Manager(f_name, l_name, age, id);
      static_cast<Manager*>(p)->SetDepartment(department);
      static_cast<Manager*>(p)->SetSalary(salary);
      break;
    
    default:
      return false;
      break;
    }

    employees.push_back(p);
    
  }
  return true;
}

void Database::ArrangeSubordinates() {
  map<string, pair<Manager*, set<Employee*>>> deps;
  for (const auto& p : employees)
  {
    if(typeid(*p) == typeid(Manager))
      deps[static_cast<Manager*>(p)->GetDepartment()].first = static_cast<Manager*>(p);
    else
      deps[static_cast<Employee*>(p)->GetDepartment()].second.insert(static_cast<Employee*>(p));
  }
  Manager* tmp;
  for(const auto& p : deps){
    tmp = static_cast<Manager*>(*find(employees.begin(), employees.end(),
    static_cast<Person*>(p.second.first)));
    for(const auto& s : p.second.second)
      tmp->AddSubordinate(s);
  }
}
bool Database::FireEmployee(const size_t& id){
  if(id < employees.size())
  {
    employees.erase(employees.begin() + id);
    return false;
  }
  else
    return true;
}

Person* Database::HireEmployee(Person* p)
{
  if(p){
    employees.push_back(p);
    return p;
  }
  return nullptr;
}

void Database::DisplayAll() const{
  for(const auto p : employees)
  {
    p->Display();
  }
}