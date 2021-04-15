#pragma once
#include <vector>
#include "employee.hpp"

class Database{
  public:
    Database(){};
    ~Database(){};//no need in destructor
    //creates "flat" database
    bool LoadFromFile(const string& file_name);
    //arranges "flat" database after loading from the file
    void ArrangeSubordinates();
    //hire a new employee
    Person* HireEmployee(Person *p);
    void DisplayDepartmentEmployees(const string& _department);
    //fire the employee
    bool FireEmployee(const size_t& id);
    void DisplayAll();
    //Add here whatever you need
  private:
    std::vector<Person*> employees;
};
