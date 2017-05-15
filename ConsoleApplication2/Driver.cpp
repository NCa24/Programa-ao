#include "stdafx.h"
#include "Driver.h"
#include <sstream>

Driver driver1;

int Driver::split_driver(string textLine)
{
	size_t found = textLine.find(";");
	size_t found2 = textLine.find(";", found + 1);
	size_t found3 = textLine.find(";", found2 + 1);
	size_t found4 = textLine.find(";", found3 + 1);
	string ID = textLine.substr(0, found - 1);
	driver1.id = atoi(ID.c_str());;
	driver1.name = textLine.substr(found + 2, found2 - found - 3);
	string maxHours = textLine.substr(found2 + 2, found3 - found2 - 3);
	driver1.maxHours = atoi(maxHours.c_str());
	string maxWeekWorkingTime = textLine.substr(found3 + 2, found4 - found3 - 3);
	driver1.maxWeekWorkingTime = atoi(maxWeekWorkingTime.c_str());;
	string minRestTime = textLine.substr(found4 + 2, textLine.size() - found4 - 2);
	driver1.minRestTime = atoi(minRestTime.c_str());
	return 1;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

int Driver::change_ID(int new_ID)
{
	driver1.id = new_ID;
}
int Driver::change_name(string new_name)
{
	driver1.name = new_name;
}
int Driver::change_maxHours(int max_Hours)
{
	driver1.maxHours = max_Hours
}
int Driver::change_maxWeekWorkingTime(int maxWeekWorkingTime)
{
	driver1.maxWeekWorkingTime = maxWeekWorkingTime;
}
int Driver::change_minRestTime(int minRestTime)
{
	driver1.minRestTime = minRestTime;
}