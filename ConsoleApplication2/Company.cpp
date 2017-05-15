#include "stdafx.h"
#include "Company.h"

extern Line Linha;
extern Driver driver1;

int Empresa::get_line()
{
	linhas.push_back(Linha);
	return 1;
}

int Empresa::get_driver()
{
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

Shift shift1;

void Empresa::distribuiServico() {


	for (unsigned i = 0 ; i < linhas.size() ; i++)
	{
		int busOrder = 0;
		int driverFrequency = 0;
		for (unsigned j = 0 ; condutores.size() ; j++)
		{
			shift1.setBusLineId(linhas[i].getId());
			shift1.setDriverId(condutores[i].getId());
			shift1.setBusOrderNumber(busOrder);
			shift1.setStartTime(driverFrequency);
			shift1.setEndTime(driverFrequency =+ condutores[i].getMaxWeekWorkingTime());
			driverFrequency =+ linhas[i].getFreq();
			busOrder++;
			shifts.push_back(shift1);
		}
	}
}