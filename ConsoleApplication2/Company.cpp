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
vector<Line> Empresa::get_linhas() {
	return linhas;
}



//////////////////////////////
// metodos set
/////////////////////////////

int Empresa::remove_line(int i)
{
	linhas.erase(linhas.begin() + i);
	return 1;
}

////////////////////////////
// outros metodos
///////////////////////////



Shift shift1;

void Empresa::distribuiServico() {

	int j = 0;
	for (unsigned int i = 0 ; i < linhas.size() ; i++)
	{
		unsigned int busOrder = 0;
		unsigned int driverFrequency = 0;
		unsigned int driverFrequencyend = 0;
		for (j ; j < condutores.size() ; j++)
		{
			shift1.setBusLineId(linhas[i].getId());
			shift1.setDriverId(condutores[i].getId());
			shift1.setBusOrderNumber(busOrder);
			shift1.setStartTime(driverFrequency);
			shift1.setEndTime(driverFrequencyend = driverFrequency + condutores[i].getMaxWeekWorkingTime());
			driverFrequency = driverFrequency + linhas[i].getFreq();
			busOrder++;
			shifts.push_back(shift1);

			cout << shifts[j].getStartTime() << endl;

		}
	}
}