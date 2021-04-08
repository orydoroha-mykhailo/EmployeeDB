#pragma once
#include <string>
#include <list>

using string = std::string;
//An abstract class
class Person{
  public:
    Person(){};
    Person(const string& _f_name, const string& _l_name,
      const size_t& _age) : age(_age),
      f_name(_f_name), l_name(_l_name){}
    virtual void Display(bool);
  protected:
    string f_name;//first name
    string l_name;//last name
    size_t age;
};

class Employee : public Person{
  public:
    Employee(){};
    Employee(const string& _f_name, const string& _l_name,
     const size_t& _age, const size_t& _id) :
    Person(_f_name, _l_name, _age), id(_id){};
    Employee(const Employee& e);
    Employee& operator=(const Employee &e);
    void SetSalary(const size_t& wage);
    void SetDepartment(const string& dept);
    void SetId(const size_t& _id);
    size_t GetId() const;
    string GetDepartment() const;
    virtual void Display() const;
    //Add here whatever you need
  protected:
    string department;
    size_t salary;
    size_t id;
};

class Manager : public Employee {
  public:
    Manager(){};
    Manager(const string& _f_name, const string& _l_name,
      size_t& _age, size_t& _id) :
    Employee(_f_name, _l_name, _age, _id){};
    Manager(const Manager& m);
    Manager& operator=(const Manager& m);
    virtual void Display(bool) const;
    //add an employee to the subordinates list
    void AddSubordinate(const Person& p);
    void DisplaySubordinates() const;
    //Add here whatever you need
  private:
    std::list<Person> subordinates;//список підлеглих
  };