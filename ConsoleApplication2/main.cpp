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
	while (getline(file2, line2))
	{
		condutor1.split_driver(line2);
		empresa1.get_driver();
	}
	file2.close();
	
	string input;
	cout << "Pretende editar Linhas ou Condutores? \n 1 para Linhas \n 2 para Condutores \n";
	cin >> input;

	if (input == "1")
	{
		cout << "Pretende adicionar nova linha, editar, eliminar ou visualizar info? \n 1 para NEW \n 2 para EDIT \n 3 para ELIMINAR \n 4 para VISUALIZAR \n";
		cin >> input;
		if (input == "1")
		{
			linha1.createLine();
			empresa1.get_line();

		}
		else if (input == "2")
		{
			cout << "Prentende:	\n 1 para ID \n 2 para Frequencia \n 3 para nome de uma paragem \n 4 para tempo entre duas paragens \n";
			cin >> input;
			if (input == "1")
			{
				cout << "Insira ID que pretende alterar \n";
				int numero;
				cin >> numero;
				cout << "Qual o novo ID \n";
				int input2;
				cin >> input2;
				for (size_t i = 0; i < empresa1.get_linhas().size(); i++)
				{
					if (empresa1.get_linhas()[i].getId() == numero)
					{
						empresa1.get_linhas()[i].setId(input2);
					}
				}
			}
			else if (input == "2")
			{
				cout << "Insira ID que pretende alterar \n";
				int numero2;
				cin >> numero2;
				cout << "Qual a nova FREQ \n";
				int numero;
				cin >> numero;
				for (size_t i = 0; i < empresa1.get_linhas().size(); i++)
				{
					if (empresa1.get_linhas()[i].getId() == numero2)
					{
						empresa1.get_linhas()[i].setFreq(numero);
					}
				}
			}
			else if (input == "3")
			{
				cout << "Insira nome da paragem que pretende alterar \n";
				string parag1;
				string parag2;
				cin.ignore();
				getline(cin, parag1);
				cout << "Qual a nova paragem \n";
				cin.ignore();
				getline(cin, parag2);
				for (size_t i = 0; i < empresa1.get_linhas().size(); i++)
				{
					for (size_t j = 0; j < empresa1.get_linhas()[i].getBusStops().size(); j++)
					if (empresa1.get_linhas()[i].getBusStops()[j] == parag1)
					{
						empresa1.get_linhas()[i].getBusStops()[j] == parag2;
					}
				}
			}
			else if (input == "4")
			{
				cout << "sorry, this feature will be available in the next version \n";
			}
			else
			{
				cout << "Accao nao disponivel! \n";
				return 1;
			}
		}
		else if (input == "3")
		{
			cout << "Que linha pretende eliminar? ";
			int linha_a_remover;
			cin.ignore();
			cin >> linha_a_remover;
			int j = 0;
			while (j < empresa1.get_linhas().size())
			{
				if (empresa1.get_linhas()[j].getId() == linha_a_remover)
				{
					empresa1.remove_line(j);
				}
				else
				{
					j++;
				}
			}
		}

		else if (input == "4")
		{
			cout << "not available \n";
		}

		else
		{
			cout << "Accao nao disponivel! \n";
			return 1;
		}
	}
		fstream file3("ficheiro de linhas.txt", ios::out | ios::trunc);
		if (!file3.is_open())
		{
			cout << "File does not exist yet !\n";
			return 1;
		}
		for (size_t i = 0; i < empresa1.get_linhas().size(); i++)
		{
			file3 << empresa1.get_linhas()[i].getId() << " ; " << empresa1.get_linhas()[i].getFreq() << " ; ";
			unsigned int j = 0;
			while (j < empresa1.get_linhas()[i].getBusStops().size())
			{
				if (j == empresa1.get_linhas()[i].getBusStops().size() - 1)
				{
					file3 << empresa1.get_linhas()[i].getBusStops()[j] << "; ";
					break;
				}
				else
				{
					file3 << empresa1.get_linhas()[i].getBusStops()[j] << ", ";
					j++;
				}
			}
			j = 0;
			while (j < empresa1.get_linhas()[i].getTimings().size())
			{
				if (j == empresa1.get_linhas()[i].getTimings().size() - 1)
				{
					file3 << empresa1.get_linhas()[i].getTimings()[j] << endl;
					break;
				}
				else
				{
					file3 << empresa1.get_linhas()[i].getTimings()[j] << ", ";
					j++;
				}
			}
		}
	return 0;
}
