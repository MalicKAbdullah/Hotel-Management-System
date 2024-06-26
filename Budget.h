#pragma once

#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;

class Budget
{
private:
	double Hotel_budget;



	double get_Budget()
	{
		return Hotel_budget;
	}

	

	bool deduct(double amount)
	{
		if (amount <= Hotel_budget)
		{
			Hotel_budget -= amount;
			

			ifstream file;
			ofstream new_file;
			file.open("Budget.txt");
			new_file.open("NEW_Budget.txt");
			if (file)
			{
				string data;
				while (!file.eof())
				{
					getline(file, data);
					new_file << data << endl;
				}
				new_file << endl;
				new_file << "AMOUNT DEDUCTED (PKR): " << amount << endl;
				new_file << "HOTEL BUDGET (PKR): " << Hotel_budget;

				new_file.close();
				file.close();

				remove("Budget.txt");
				rename("NEW_Budget.txt", "Budget.txt");
					
			}

			cout << "SALARY PAID SUCCESSFULLY." << endl;
			return true;
		
		}
		else
		{
			cout << "NOT ENOUGH HOTEL BUDGET." << endl;
			return false;
		}

	}

	double set_Budget()
	{
		double amount;
		do
		{
			cout << "ENTER BUDGET AMOUNT : ";
			cin >> amount;
		} while (amount < 0);

		Hotel_budget = amount;

		ifstream file;
		ofstream new_file;
		file.open("Budget.txt");
		new_file.open("NEW_Budget.txt");
		if (file)
		{
			string data;
			while (!file.eof())
			{
				getline(file, data);
				new_file << data << endl;
			}
			new_file << endl;
			new_file << "MANAGER HAS UPDATED THE HOTEL BUDGET TO (PKR): " << Hotel_budget;

			new_file.close();
			file.close();

			remove("Budget.txt");
			rename("NEW_Budget.txt", "Budget.txt");


		}


		return 0;
	}

	public:


		friend class Manager;


		Budget()
		{
			Hotel_budget = 0;
			ifstream file;
			file.open("Budget.txt");

			if (file)
			{
				string data;
				while (!file.eof())
				{
					file >> data;
				}
				Hotel_budget = stod(data);

			}

		}

		void add(double amount)
		{
			Hotel_budget += amount;

			fstream file;
			file.open("Budget.txt",ios::app);

			if (file)
			{
				file << endl << endl;

				file << "AMOUNT ADDED (PKR): " << amount << endl;
				file << "HOTEL BUDGET (PKR): " << Hotel_budget;
			}
			file.close();

		}
		


};
