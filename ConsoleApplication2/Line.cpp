#include "stdafx.h"
#include "Line.h"
#include <sstream>



Line::Line(string textLine){
	size_t found = textLine.find(";");
	size_t found2 = textLine.find(";", found + 1);
	size_t found3 = textLine.find(";", found2 + 1);
	size_t found4 = textLine.find(",", found + 1); //virgulas nas paragens
	size_t found5 = textLine.find(",", found3 + 1); //virgulas nos tempos
	string ID = textLine.substr(0, found - 1);
	string FREQ = textLine.substr(found + 2, found2 - found - 3);
	stringstream convert(FREQ);
	convert >> freq;
	stringstream convert(ID);
	convert >> id;
	int aux;

	while (found4 <= found3) //armazenar paragens
	{
		busStopList.push_back(textLine.substr(found2 + 2, found4 - found2 - 2));
		found2 = found4;
		found4 = textLine.find_first_of(",;", found4 + 1);
	}

	while (found5 <= textLine.size()) //armarzenar tempos
	{
		if (found5 == (textLine.size() - 1))
		{
			stringstream convert(textLine.substr(found3 + 2, textLine.size() - 1 - found3 - 2));
			convert >> aux;
			timesList.push_back(aux);
		}
		else
		{
			stringstream convert (textLine.substr(found3 + 2, found5 - found3 - 2));
			convert >> aux;
			timesList.push_back(aux);
			found3 = found5;
			found5 = textLine.find(",", found5 + 1);
		}
	}

  // INITIALISATION CODE GOES IN HERE
  

}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

unsigned int Line::getFreq() const {
	return id;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}


//SET METHODS

int changeID()
{
	while (i < .size())
	{
		if (alterar == linhas[i].ID)
			linhas[i].ID = introduzir;
		i++;
	}
	return 1;
}