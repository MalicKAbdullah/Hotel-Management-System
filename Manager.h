#pragma once
#include "Person.h"
#include "Budget.h"
#include "Hotel.h"
#include <fstream>

class Manager : public Person
{
private:
	string userid;
	string username;
	string password;

public:

	Manager()
	{
		ifstream file;
		file.open("Manager.txt");
		string id;
		getline(file, id);
		int index;
		index = id.find(':');
		//cout << index;
		id = id.substr(index + 2);

		string user;
		getline(file, user);
		index = user.find(':');
		user = user.substr(index + 2);

		string pass;
		getline(file, pass);
		index = pass.find(':');
		pass = pass.substr(index + 2);


		/*	cout << id;
			cout << endl;
			cout << user << endl << pass << endl;*/

		userid = id;
		username = user;
		password = pass;

		file.close();
		setFromFile(userid);
		// set Person Members of Manager USing file handling. Enter name,address,etc in file . 

	}

	~Manager()
	{
	

		
	}

	void PersonDetails()
	{
		ifstream file;
		file.open("Person.txt");
		string line;

		while (!file.eof())
		{
			getline(file, line);
			cout << line << endl;
		}

		file.close();

	}

	string getuserid()
	{
		return userid;
	}

	string getusername()
	{
		return username;
	}

	string getpassword()
	{
		return password;
	}

	void setSalary(string id,int x)
	{
		Employee obj;
		obj.setemployee(id);
		obj.setSalary(x);
	
	}

	void setHotelBudget()
	{
		Budget obj;
		obj.set_Budget();
	}

	void setSalaryPaid(string id, int x)
	{
		Employee obj;
		obj.setemployee(id);
		obj.setSalaryPaid(x);
	
	}

	void setSalaryStatus(string id, bool x)
	{
		Employee obj;
		obj.setemployee(id);
		obj.setSalaryStatus(x);
	
	}


	void changePassword()
	{
		string oldpass;
		do
		{
			cout << "  ENTER OLD PASSWORD : ";
			getline(cin, oldpass);

			if (!(oldpass == password))
				cout << "  PASSWORD IS WRONG." << endl;

		} while (!(oldpass == password));
		
		string pass1;
		do
		{
			cout << "  ENTER NEW PASSWORD : ";
			getline(cin, password);

			cout << "  ENTER PASSWORD AGAIN : ";
			getline(cin, pass1);

			if (!(password == pass1))
				cout << "  PASSWORD DOES NOT MATCH ." << endl;

			if (password == oldpass)
				cout << "  CHOOSE A NEW PASSWORD." << endl;
		} while ((password == oldpass) || (!(password == pass1)));

	
		ofstream file1;
		file1.open("Manager.txt");

		file1 << "Manager Id : " << userid << endl;
		file1 << "Username : " << username << endl;
		file1 << "Password : " << password;

		file1.close();

	}

	void changeUsername()
	{
		string oldusername;
		do
		{
			cout << "  ENTER OLD USERNAME : ";
			getline(cin, oldusername);

			if (!(oldusername == username))
				cout << "  USERNAME IS WRONG." << endl;

		} while (!(oldusername == username));

		string user;
		do
		{
			cout << "  ENTER NEW USERNAME : ";
			getline(cin, username);

			cout << "  ENTER USERNAME AGAIN : ";
			getline(cin, user);

			if (!(username == user))
				cout << "  USERNAME DOES NOT MATCH ." << endl;

			if (oldusername == user)
				cout << "  CHOOSE A NEW USERNAME." << endl;
		} while ((oldusername == user) || (!(username == user)));

		ofstream file1;
		file1.open("Manager.txt");

		file1 << "Manager Id : " << userid << endl;
		file1 << "Username : " << username << endl;
		file1 << "Password : " << password;

		file1.close();

	}

	void getmanager()
	{
		getperson();
		cout << " Userid : " << userid << endl;
		cout << " Username : " << username << endl;
		cout << " Password : " << password;
		cout << endl;
		/*if pass matches file data
			cout << "LOGIN  SUCCESSFUL !" << endl;
		if pass doesn't match file data
			cout << "LOGIN FAILED ! INVALID PASSWORD " << endl;*/



	}

	void setNewEmployee()
	{
		Employee obj;
		obj.setnewemployee();
	}

	void EmployeeDetails()
	{

		ifstream file;
		file.open("Employee.txt");

		if (file)
		{
			string line;
			while (!file.eof())
			{
				getline(file, line);
				cout <<" "<< line << endl;

			}

		}
		cout << endl;
	}

	void PayEmployeeSalary()
	{
	
		string id;
		cout << "ENTER EMPLOYEE ID : ";
		getline(cin, id);
		

		Employee emp_obj;
		emp_obj.setemployee(id);

		Budget budget_obj;

		if (!emp_obj.salaryStatus)
		{
			if (budget_obj.deduct(emp_obj.salaryPaid))
				emp_obj.setSalaryStatus(true);

		}
		else
			cout << "SALARY ALREADY PAID." << endl;
	}

	void HotelDetails()
	{
		ifstream hotel;
		hotel.open("Hotel.txt");

		if (hotel)
		{
			string temp;
			while (!hotel.eof())
			{
				getline(hotel, temp);
				cout <<" "<< temp << endl;
			}


		}
		cout << endl;
	}

	void setHotel()
	{
		Hotel obj;
		obj.setHotel();

	}

	void BudgetDetails()
	{
		ifstream file;
		string line;

		file.open("Budget.txt");
		getline(file, line);
		getline(file, line);

		while (!file.eof())
		{
			getline(file, line);

			cout << line << endl;
		}
	}
};

