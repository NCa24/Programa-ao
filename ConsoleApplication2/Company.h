#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Driver.h"
#include "Shift.h"


using namespace std;

class Empresa{
 private:
  string nome;
  vector<Driver> condutores;
  vector<Line> linhas;
  vector<Shift> shifts;

 public:
	 int get_line();
	 int get_driver();
  // metodos get
  string getNome() const;
  // metodos set
  int Empresa::remove_line(int i);
  // outros metodos
  void distribuiServico(); // funcao que implementa a afectacao de servico
  vector<Line> get_linhas();
};
