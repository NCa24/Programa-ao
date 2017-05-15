#include "stdafx.h"
#include "Driver.h"
#include <sstream>

extern Driver driver1;

int Driver::split_driver(string textLine)
{
	size_t found = textLine.find(";");
	size_t found2 = textLine.find(";", found + 1);
	size_t found3 = textLine.find(";", found2 + 1);
	size_t found4 = textLine.find(";", found3 + 1);
	string ID = textLine.substr(0, found - 1);
	stringstream convert(ID);
	convert >> driver1.id;
	driver1.name = textLine.substr(found + 2, found2 - found - 3);
	string maxHours = textLine.substr(found2 + 2, found3 - found2 - 3);
	stringstream convert(maxHours);
	convert >> driver1.maxHours;
	string maxWeekWorkingTime = textLine.substr(found3 + 2, found4 - found3 - 3);
	stringstream convert(maxWeekWorkingTime);
	convert >> driver1.maxWeekWorkingTime;
	string minRestTime = textLine.substr(found4 + 2, textLine.size() - found4 - 2);
	stringstream convert(minRestTime);
	convert >> driver1.minRestTime;
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
