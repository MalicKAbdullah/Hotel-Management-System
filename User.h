#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Employee.h"
#include "Manager.h"

string red = "\u001b[31;1m";
string reset = "\u001b[0m";
string blue = "\u001b[34;1m";

class User : public Employee,public Manager
{
private:
	string employeeid;
	string managerid;
	string manager_username;
	string manager_password;

public:
	void setemployeeid(string a)
	{
		employeeid = a;
	}

	User()
	{
		employeeid = managerid = manager_username = manager_password = " ";

	}

	string setManager()
	{
		cout << blue<<"  ENTER MANAGER ID : "<<reset;
		getline(cin, managerid);

		cout << blue<<"  ENTER USERNAME   : "<<reset;
		getline(cin, manager_username);

		cout << blue<<"  ENTER PASSWORD   : "<<reset;
		getline(cin, manager_password);

		return managerid;


	}

	bool validate_employee()
	{
		ifstream file;
		file.open("Employee.txt");
		while (!file.eof())
		{
			string temp_id;
			file >> temp_id;

		/*	temp_id = temp_id.substr(0, 7);*/

			//cout << temp_id;
			//cout << endl;

			if (temp_id == employeeid)
			{
				// User class will call the setEmployee() and set the employee with the id provided i.e, employeeid if found
				return true;

			}


		}

		return false;

	}

	bool validate_manager()
	{

		if (getuserid() == managerid && getusername() == manager_username && getpassword() == manager_password)
			return true;
		else
			return false;

	}

	~User()
	{

		employeeid = managerid = manager_username = manager_password = " ";

	}
};


