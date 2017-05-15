#include "stdafx.h"
#include "Company.h"

extern Line Linha;
extern Driver driver1;

int Empresa::get_line_driver(string nome, string fichCondutores, string fichLinhas)
{
	linhas.push_back(Linha);
	condutores.push_back(driver1);
	return 1;
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
void Empresa::distribuiServico() {

	Shift shift1;

	for (unsigned i = 0 ; i < linhas.size() ; i++)
	{
		busOrder = 0;
		driverFrequency = 0;
		for (unsigned j = 0 ; condutores.size() ; j++)
		{
			shift1.setBusLineId(linhas[i].id);
			shift1.setDriverId(condutores[i].id);
			shift1.setBusOrderNumber(busOrder);
			shift1.setStartTime(driverFrequency);
			shift1.setEndTime(driverFrequency =+ condutores[i].maxHours)
			driverFrequency += linhas[0].freq;
			busOrder++;
			shifts.push_back(shift1);
		}
	}
}
