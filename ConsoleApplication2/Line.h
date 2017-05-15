#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Line{
 private:
  unsigned int id;
  unsigned int freq;
  vector<string> busStopList;
  vector<int> timesList;
  vector <pair<pair<string, string>, string>> tempo_viagem;
 public:
  Line(string textLine);
  // metodos get
  unsigned int getFreq() const;
  unsigned int getId() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  // set methods
  int changeID(int new_ID);
  // other methods

};
