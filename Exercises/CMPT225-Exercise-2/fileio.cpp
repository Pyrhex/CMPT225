#include <iostream>
#include <fstream>
#include <string>
#include "Students.hpp"
using namespace std;
int main(){
  string firstname;
  double num;
  fstream infile;
  infile.open("afile.txt");
  int count;
  while( infile >> firstname >> num)
  {
      count++; //counting number of lines/names
  }
  Students list[count]; //creating array of "Students" with the size of number of lines
  infile.close(); //close file
  infile.open("afile.txt"); //reopening file
  count = 0; //resetting the counter to reuse it
  double total = 0; //total of all numbers added
  while( infile >> firstname >> num)
  {
      list[count].insert(firstname, num); //adding attributes to each object in array
      total += list[count].getGrade(); //adding number attribute to total
      count++;
  }
  infile.close();
  infile.open("afile.txt"); //reopen file
  infile << "The average of all the numbers is " << total/count << endl; //writing average to file
  for(int i = 0; i < count; i++){
    infile << list[i].getName() << " " << list[i].getGrade() << endl; //writing the names with numbers back into file
  }
  infile.close(); //closing file
  return 0;


}
