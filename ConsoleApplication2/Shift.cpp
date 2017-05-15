#include "stdafx.h"
#include "Shift.h"
#include "Company.h"

extern Driver driver1;

using namespace std;
Shift::Shift(  unsigned int linha, unsigned int condutor, unsigned int autocarro, unsigned int inicio, unsigned int fim){
  
  // INITIALISATION CODE GOES IN HERE

	busLineId = linha;
	driverId = condutor;
	busOrderNumber = autocarro;
	startTime = inicio;
	endTime = fim;
}

Shift shift1;
Company company1; // criar empresa?
/*
 * allShifts.pushback(shift1)
 * allShifts[i].driverId == driver requested
 *
 */

void Shift::assignShift() {


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
			shift1.setEndTime(condutores[i].maxHours)
			driverFrequency += linhas[0].freq;
			busOrder++;
		}
	}
}


// metodos get
unsigned int Shift::getBusLineId() const{
  return busLineId;
}

unsigned int Shift::getDriverId() const{
  return driverId;
}
unsigned int Shift::getBusOrderNumber() const{
  return busOrderNumber;
}

unsigned int Shift::getStartTime() const{
  return startTime;
}

unsigned int Shift::getEndTime() const{
  return endTime;
}

///////////////
// set methods
//////////////

void Shift::setBusLineId(unsigned int busLineId){
  this->busLineId = busLineId;
}

void Shift::setDriverId(unsigned int driverId){
  this->driverId = driverId;
}

void Shift::setBusOrderNumber(unsigned int busOrderNumber){
  this->busOrderNumber = busOrderNumber;
}

void Shift::setStartTime(unsigned int startTime){
  this->startTime = startTime;
}

void Shift::setEndTime(unsigned int endTime){
  this->endTime = endTime;
}
