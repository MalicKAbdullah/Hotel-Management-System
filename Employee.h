#pragma once
#include "Person.h"
#include "Rooms.h"
#include "GuestDetails.h"
#include "Guest.h"
#include "Budget.h"

class Employee : public Person
{

private:

	int salary;
	int salaryPaid;
	bool  salaryStatus;

	void setSalary(int x)
	{
		salary = x;
	}
	
	void setSalaryPaid(int x)
	{
		salaryPaid = x;
	}
	void setSalaryStatus(bool x)
	{
		salaryStatus = x;

	}

	void setnewemployee(string a, int b, int c, bool d)
	{
		
		setperson();

	
		string temp;
		ifstream file;
		file.open("Employee.txt");

		string aa = a.substr(0, 3);
		for(int i=0;i<3;i++)
			if (aa[i] >= 'A' && aa[i] <= 'Z')
			aa[i] = aa[i] + 32;

		while (!(file.eof()))
		{
			getline(file, temp);
		}

		int x = stoi(temp.substr(5, 2))+1;

		empID = "e_" + aa + to_string(x);
		salary = b;
		salaryPaid = c;
		salaryStatus = d;
		ofstream setter;
		setter.open("Employee.txt", ios::app);
		setter << endl;
		setter << "e_" << aa << x << "\t\t    " << b << "\t\t" << c << "\t\t\t" << d;
		setter.close();

		update_employee_file();
	}

	void setnewemployee()
	{
		int b, c;
		bool d;
		setperson();

		cout << " ENTER EMPLOYEE SALARY : ";
		cin >> b;
		cout << " ENTER SALARY PAID : ";
		cin >> c;
		cout << " ENTER SALARY STATUS : ";
		cin >> d;
		string temp;
		ifstream file;
		file.open("Employee.txt");

		string aa = name.substr(0, 3);
		for (int i = 0; i < 3; i++)
			if (aa[i] >= 'A' && aa[i] <= 'Z')
				aa[i] = aa[i] + 32;

		while (!(file.eof()))
		{
			getline(file, temp);
		}

		int x = stoi(temp.substr(5, 2)) + 1;

		empID = "e_" + aa + to_string(x);
		salary = b;
		salaryPaid = c;
		salaryStatus = d;
		ofstream setter;
		setter.open("Employee.txt", ios::app);
		setter << endl;
		setter << "e_" << aa << x << "\t\t    " << b << "\t\t" << c << "\t\t\t" << d;
		setter.close();

		update_employee_file();
	}

	void update_employee_file()
	{
														// This  function will be called after setting a new employee
		ifstream file1;
		file1.open("Person.txt");
		ofstream newfile;
		newfile.open("p.txt");
		if (file1)
		{
			string temp;
			while (!file1.eof())
			{
				getline(file1, temp);

				if (temp == "Employee-End")
				{
					newfile << "Employee_Id : " << empID << endl;
					newfile << "Name : " << name << endl;
					newfile << "Gender : " << gender << endl;
					newfile << "Age : " << age << endl;
					newfile << "Contact : " << contact << endl;
					newfile << "Address : " << address << endl;
					newfile << endl;
				}

				newfile << temp;
				newfile << endl;
			}

			file1.close();
			newfile.close();

			remove("Person.txt");
			rename("p.txt", "Person.txt");
		}

	}


public:

	Employee()
	{
		empID = "  ";
		salary = salaryPaid = salaryStatus = 0;
	}

	friend class Manager;
	Rooms* hotelRooms;

	string empID;

	GuestDetails* guest_details;
	//Transaction * trans_details;
	Budget budgetupdate;

	void setRoomsobj(Rooms& hotel)
	{
		hotelRooms = &hotel;
	}
	
	void setGuestDetailsObj(GuestDetails& obj)
	{
		guest_details = &obj;
	}

	void setBudgetObj(Budget& obj)
	{
		budgetupdate = obj;
	}


	Employee(Employee& obj)
	{
		this->empID = obj.empID;
		this->salary = obj.salary;
		this->salaryPaid = obj.salaryPaid;
		this->salaryStatus = obj.salaryStatus;

		setnewemployee(empID, salary, salaryPaid, salaryStatus);
	}


	Employee(string id, int a, int b, bool c)  //manager will provide the details and new employee will be created and instantiated. 
	{
		setnewemployee(id, a, b, c);

	}

	void getemployee()
	{
		cout << "Employee Id : " << empID << endl;
		cout << "Employee Salary : " << salary << endl;
		cout << "Employee Salary Paid : " << salaryPaid << endl;
		cout << "Employee Salary Status : " << salaryStatus << endl;
	}

	void setemployee(string str)  // After Authentication, Employee will be set acc to its Id
	{

		Employee obj;
		ifstream readEmployee;
		string  id;
		int sal, pay;
		bool status;
		readEmployee.open("Employee.txt");

		string temp;
		getline(readEmployee, temp);
		getline(readEmployee, temp);
	

		bool check = false;
		while (!readEmployee.eof())
		{
			readEmployee >> id >> sal >> pay >> status;

			if (id == str)
			{
				check = true;
				break;
			}
		}

		if (check == true)
		{
			empID = id;
			salary = sal;
			salaryPaid = pay;
			salaryStatus = status;

		}

		setFromFile(empID);

		readEmployee.close();
	}


	bool checkemployee(string str) 
	{

		Employee obj;
		ifstream readEmployee;
		string  id;
		int sal, pay;
		bool status;
		readEmployee.open("Employee.txt");

		string temp;
		getline(readEmployee, temp);
		getline(readEmployee, temp);


		bool check = false;
		while (!readEmployee.eof())
		{
			readEmployee >> id >> sal >> pay >> status;

			if (id == str)
			{
				check = true;
				return true;
				break;
			}
		}

		return false;

		readEmployee.close();
	}

	~Employee()
	{
		ifstream file;
		ofstream newfile;
		file.open("Employee.txt");
		newfile.open("newemployee.txt");
		string temp;

		getline(file, temp);
		newfile << temp;

		if (file)
		{
		
			while (!file.eof())
			{
			
				getline(file, temp);
				string sub = temp.substr(0, 7);
				if (sub == empID)
				{
					newfile << endl<< empID << "\t\t   " << salary << "\t\t" << salaryPaid << "\t\t\t" << salaryStatus;
				}
				else
				{
					newfile << endl<<temp;
				}


			}
	
			file.close();
			newfile.close();
		}
		

		remove("Employee.txt");
		rename("newemployee.txt","Employee.txt");
	}

};


void loadEmployee(Employee array[5])
{
	cout << "check" << endl;
	ifstream loader;
	string id, sal, pay, status;
	loader.open("staff1.txt");
	int i = 0;
	int eCount = 0;
	loader >> id >> sal >> pay >> status;
	while (!loader.eof())
	{
		//cout << "employee number " << ++eCount << endl;
		Employee e(id, stoi(sal), stoi(pay), stoi(status));
		//cout << e.empID << endl;
		array[i++] = e;
		loader >> id >> sal >> pay >> status;
	}
	loader.close();
	for (int x = 0; x < 4; x++)
	{
		cout << " employee " << x << " id : " << array[x].empID << endl;

	}

}


