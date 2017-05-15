#include "stdafx.h"
#include "Company.h"

extern Line Linha;
extern Driver driver1;

int Empresa::get_line_driver(string nome, string fichCondutores, string fichLinhas)
{
	linhas.push_back(Linha);
	condutores.push_back(driver1);
}

////////////////////////////////
// metodos get
///////////////////////////////
string Empresa::getNome() const{
  return nome;
}

//////////////////////////////
// metodos set
/////////////////////////////

////////////////////////////
// outros metodos
///////////////////////////
void Empresa::distribuiServico(){
}
