#include "stdafx.h"
#include "Line.h"
#include <sstream>
#include <utility>

using namespace std;

	Line Linha;

	int Line::iterative_Line(string textLine) {
	size_t found = textLine.find(";");
	size_t found2 = textLine.find(";", found + 1);
	size_t found3 = textLine.find(";", found2 + 1);
	size_t found4 = textLine.find(",", found + 1); //virgulas nas paragens
	size_t found5 = textLine.find(",", found3 + 1); //virgulas nos tempos
	string ID = textLine.substr(0, found - 1);
	string FREQ = textLine.substr(found + 2, found2 - found - 3);
	stringstream convert(FREQ);
	convert >> Linha.freq;
	stringstream convert(ID);
	convert >> Linha.id;
	int aux;
	Linha.busStopList.clear(); //limpar antes de começar a escrever
	Linha.timesList.clear(); //construtor para todas as linhas
	Linha.tempo_viagem.clear();
	while (found4 <= found3) //armazenar paragens
	{
		Linha.busStopList.push_back(textLine.substr(found2 + 2, found4 - found2 - 2));
		found2 = found4;
		found4 = textLine.find_first_of(",;", found4 + 1);
	}

	while (found5 <= textLine.size()) //armarzenar tempos
	{
		if (found5 == (textLine.size() - 1))
		{
			stringstream convert(textLine.substr(found3 + 2, textLine.size() - 1 - found3 - 2));
			convert >> aux;
			Linha.timesList.push_back(aux);
		}
		else
		{
			stringstream convert(textLine.substr(found3 + 2, found5 - found3 - 2));
			convert >> aux;
			Linha.timesList.push_back(aux);
			found3 = found5;
			found5 = textLine.find(",", found5 + 1);
		}
	}

	//store tempo entre paragens associado as respectivas paragens

	int i = 0;
	int j = 0;
	int k = 0;
	while (i < (busStopList.size() - 1))
	{
		Linha.tempo_viagem[k].first.first = busStopList[i];
		Linha.tempo_viagem[k].first.second = busStopList[i + 1];
		Linha.tempo_viagem[k].second = timesList[j];
		i++;
		j++;
		k++;
	}
	return 1;
}

// INITIALISATION CODE GOES IN HERE

////////////////
// get methods
////////////////

unsigned int Line::getId() const {
	return id;
}

unsigned int Line::getFreq() const {
	return id;
}

vector<string> Line::getBusStops() const {
	return busStopList;
}

vector<int> Line::getTimings() const {
	return timesList;
}


//SET METHODS

int Line::changeID(int new_ID)
{
	Linha.id = new_ID;
	return 1;
}

int Line::changeFreq(int new_freq)
{
	Linha.freq = new_freq;
	return 1;
}

int Line::changeBusStop(string to_change, string new_bus_stop)
{
	while (int i = 0 < Linha.busStopList.size())
	{
		if (Linha.busStopList[i] == to_change)
		{
			Linha.busStopList[i] == new_bus_stop;
			break;
		}
	}
	return 1;
}

int Line::changeTime(string parag1, string parag2, int new_time)
{
	int j = 0;
	while (j < Linha.tempo_viagem.size())
	{
		if ((Linha.tempo_viagem[j].first.first == parag1 && Linha.tempo_viagem[j].first.second == parag2) || (Linha.tempo_viagem[j].first.first == parag2 && Linha.tempo_viagem[j].first.second == parag1))
		{
			Linha.tempo_viagem[j].second = new_time;
			break;
		}
		j++;
	}
	return 1;
}