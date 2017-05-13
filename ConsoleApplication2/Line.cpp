#include "stdafx.h"
#include "Line.h"
#include <sstream>

vector <Line> LinhasExistentes //vector que contem todas as linhas

//Line temporario; //objecto que depois entra em LinhasExistentes

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
	busStopList.clear(); //limpar antes de começar a escrever
	timesList.clear(); //construtor para todas as linhas
	tempo_viagem.clear();
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

	//store tempo entre paragens associado as respectivas paragens

		int i = 0;
		int j = 0;
		int k = 0;
		while (i < (busStopList - 1))
		{
			tempo_viagem[k].first.first = busStopList[i];
			tempo_viagem[k].first.second = busStopList[i + 1];
			tempo_viagem[k].second = armazena_temp_tempos[j];
			temp.tempo_viagem.push_back(temp3);
			i++;
			j++;
			k++;
		}
	LinhasExistentes.push_back(Line); //LINHA ENTRA NO VECTOR
	return 1;
}

	// INITIALISATION CODE GOES IN HERE

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

int Line::changeID(int new_ID)
{
	id = new_ID;
	return 1;
}

int Line::changeFreq(int new_freq)
{
	freq = new_freq;
	return 1;
}

int Line::changeBusStop(string to_change, string new_bus_stop)
{
	while (int i= 0 < busStopList)
	{
		if (busStopList[i] == to_change)
		{
			busStopList[i] == new_bus_stop;
			break;
		}
	}
	return 1;
}

int Line::changeTime(string parag1, string parag2, int new_time)
{
	int j = 0;
		while (j < timesList())
		{
			if ((timesList[j].first.first == parag1 && timesList[j].first.second == parag2) || (timesList[j].first.first == parag2 && timesList[j].first.second == parag1))
				{
				timesList[j].second = new_time;
				break;
				}
			j++;
		}
		return 1;
}

