#include <iostream>
#include <string>
using namespace std;

class Students
{
  string name;
  double grade;
public:
  Students();
  void insert(string name, double grade);
  string getName();
  double getGrade();
};
