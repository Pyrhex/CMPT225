#include <iostream>
#include "Students.hpp"
Students::Students(){
  name = "";
  grade = 0;
}
void Students::insert(string firstname, double numgrade){
  name = firstname;
  grade = numgrade;
}
string Students::getName(){
  return name;
}
double Students::getGrade(){
  return grade;
}
