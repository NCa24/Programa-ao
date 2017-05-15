#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Shift.h"


using namespace std;

class Driver{
 private:
  unsigned int id;
  string name;
  unsigned int maxHours;        // maximum duration of a shift
  unsigned int maxWeekWorkingTime;  // maximum number of hours of work in a week
  unsigned int minRestTime;     // minimum number of rest hours between shifts
  // assigned shifts in Company.h

 public:
  // get methods
  unsigned int getId() const;
  string getName() const;
  unsigned int getShiftMaxDuration() const;
  unsigned int getMaxWeekWorkingTime() const;
  unsigned int getMinRestTime() const;
  vector<Shift> getShifts() const;

  // outher methods
  int split_driver(string textLine);
  int change_ID(int new_ID);
  int change_name(string new_name);
  int change_maxHours(int max_Hours);
  int change_maxWeekWorkingTime(int maxWeekWorkingTime);
  int change_minRestTime(int minRestTime);

};
