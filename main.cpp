#include "employee.hpp"
#include "database.hpp"

int main()
{
  Database db;
  db.LoadFromFile("input.csv");
  db.ArrangeSubordinates();
  db.DisplayAll();
  return 0;
}