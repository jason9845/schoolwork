#include <iostream>
#include "date.h"
using namespace std;

int main() {
  int day, month, year;
  cout << "Enter today's date (day month year): ";
  cin >> day >> month >> year;
  Date today(day, month, year);

  cout << "Today is ";
  //TO DO: display the date of today
	today.print();

  Date deadline;
  //TO DO: set the date of assignment's deadline
	today.set(15, 10, 2015);

  cout << "The deadline of this assessment is ";
  //TO DO: display the date of assignment's deadline
	today.print();

  return 0;
};
