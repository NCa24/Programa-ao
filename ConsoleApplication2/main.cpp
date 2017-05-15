#include "stdafx.h"
#include "Line.h"
#include "Driver.h"
#include "Company.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
	Empresa empresa1;
	Line linha1;
	Driver condutor1;
	fstream file("ficheiro de linhas.txt", ios::in);
	string line;
	if (!file.is_open())
	{
		cout << "File does not exist yet !\n";
		return 1;
	}
	while (getline(file, line))
	{
		linha1.iterative_Line(line);
		empresa1.get_line();

	}
	file.close();
	fstream file2("ficheiro de condutores.txt", ios::in);
	string line2;
	if (!file2.is_open())
	{
		cout << "File does not exist yet !\n";
		return 1;
	}
	while (getline(file, line2))
	{
		condutor1.split_driver(line2);
		empresa1.get_driver();
	}
	file2.close();

	return 0;
}
