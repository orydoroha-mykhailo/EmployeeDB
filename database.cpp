#include "database.hpp"
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

enum class job_type{
  EMPLOYEE,
  MANAGER
};
istream& operator>>(istream& stream, job_type& jt) {
  bool tmp; 
  stream >> tmp;
  if(tmp)
    jt = job_type::EMPLOYEE;
  else
    jt = job_type::MANAGER;
    return stream;
}

bool Database::LoadFromFile(const string& filename)
{
  job_type person_position;
  size_t id;
  string name;
  string surname;
  size_t age;
  string depart;
  size_t salary;

  ifstream csv(filename, ios::out);
  while (!csv.eof())
  {
    csv >> person_position;
    csv.ignore(1);
    csv >> id;
    csv.ignore(1);
    csv >> name;
    csv.ignore(1);
    csv >> surname;
    csv.ignore(1);
    csv >> age;
    csv.ignore(1);
    csv >> depart;
    csv.ignore(1);
    csv >> salary;
    csv.ignore(1);
    Person *p;
    switch (person_position) {
    case job_type::EMPLOYEE:
      p = new Employee(name, surname, age, id);
      static_cast<Employee*>(p)->SetDepartment(depart);
      static_cast<Employee*>(p)->SetSalary(salary);
      break;

    case job_type::MANAGER:
      new Manager;
      p = new Manager(name, surname, age, id);
      static_cast<Manager*>(p)->SetDepartment(depart);
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

void Database::DisplayAll(){

}