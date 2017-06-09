#include "stdafx.h"
#include "Line.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <stdlib.h>

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
	Linha.id = atoi (ID.c_str());
	Linha.freq = atoi(FREQ.c_str());
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
			stringstream convert(textLine.substr(found3 + 2, textLine.size() - 1 - found3 - 1));
			convert >> aux;
			Linha.timesList.push_back(aux);
			break;
		}
		else
		{
			stringstream convert(textLine.substr(found3 + 2, found5 - found3 - 2));
			convert >> aux;
			Linha.timesList.push_back(aux);
			found3 = found5;
			found5 = textLine.find(",", found5 + 1);
			if (found5 > textLine.size())
			found5 = textLine.size() - 1;
		}
	}

	//store tempo entre paragens associado as respectivas paragens

	int i = 0;
	int j = 0;
	int k = 0;
	pair <pair<string, string>, int> aux2;
	while (i < (Linha.busStopList.size() - 1))
	{
		aux2.first.first = Linha.busStopList[i];
		aux2.first.second = Linha.busStopList[i + 1];
		aux2.second = Linha.timesList[j];
		Linha.tempo_viagem.push_back(aux2);
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
	return freq;
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


void Line::setId(int id) {
	this->id = id;
}
void Line::setFreq(int freq) {
	this->freq = freq;
}

void Line::setBusStops(vector<string> busStopList) {
	this->busStopList = busStopList;
}

void Line::setTimesList(vector<int> timesList) {
	this->timesList = timesList;
}

void Line::setTempoViagens(vector <pair<pair<string, string>, int>> tempo_viagem) {

	this->tempo_viagem = tempo_viagem;
}

void Line::createLine()
{

	Linha.busStopList.clear(); //limpar antes de começar a escrever
	Linha.timesList.clear(); //construtor para todas as linhas
	Linha.tempo_viagem.clear();
	string perguntasLinha[4] = {
		"inserir número identificador único ",
		"inserir frequência de circulação dos autocarros na linha (em minutos)",
		"inserir lista com a sequência das paragens que a constituem. quando nao quiser inserir mais paragens escreva 'end'  ",
		"inserir lista com os tempos (em minutos) de viagem entre paragens. quando tiver inserido todos os tempos escreva 'end' "
	};

	fstream file("ficheiro de linhas.txt", ios::app);
	cin.ignore();
	cout << perguntasLinha[0] << endl;
	int var;
	cin >> var;
	Linha.setId(var);
	cout << perguntasLinha[1] << endl;
	cin >> var;
	Linha.setFreq(var);
	cout << perguntasLinha[2] << endl;
	cin.ignore();
	string var2;
	while (var2 != "end")
	{
		cout << "inserir paragem" << endl;
		getline(cin, var2);
		if (var2 == "end")
			break;
		Linha.busStopList.push_back(var2);
	}
	string var3;
	do
	{
		cout << "inserir tempo" << endl;
		getline(cin, var3);
		if (var3 == "end")
			break;
		var = atoi(var3.c_str());
		Linha.timesList.push_back(var);
	} while (var3 != "end");
}