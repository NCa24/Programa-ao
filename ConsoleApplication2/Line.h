#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>



using namespace std;

class Line {
private:
	unsigned int id;
	unsigned int freq;
	vector<string> busStopList;
	vector<int> timesList;
	vector <pair<pair<string, string>, int>> tempo_viagem;
public:
	int iterative_Line(string textLine);
	// metodos get
	unsigned int getFreq() const;
	unsigned int getId() const;
	vector<string> getBusStops() const;
	vector<int> getTimings() const;
	// set methods
	int changeID(int new_ID);
	int changeTime(string parag1, string parag2, int new_time);
	int changeBusStop(string to_change, string new_bus_stop);
	int changeFreq(int new_freq);
	// other methods
	void setId(int);
	void setFreq(int);
	void setBusStops(vector<string>);
	void setTimesList(vector<int>);
	void setTempoViagens(vector <pair<pair<string, string>, int>>);
	void createLine();

};
