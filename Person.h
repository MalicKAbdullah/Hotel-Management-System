#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person
{
protected:
	string name;
	string gender;
	int age;
	string contact;
	string address;

public:
	
	Person()
	{
		name = gender = address = contact= " ";
		age = 0;

	

	}
	Person(string a, string b, int c, int p, string ad)
	{
		name = a;
		gender = b;
		age = c;
		contact = p;
		address = ad;
	}
	void setperson()
	{
		cout << " Enter Name : ";
		getline(cin, name);
		cout << " Enter Gender : ";
		getline(cin, gender);
		cout << " Enter Age : ";
		cin >> age;
		cout << " Enter Contact Number : ";
		cin >> contact;
		cin.ignore();
		cout << " Enter Address : ";
		getline(cin, address);


	}
	/*string getname(Person &obj)
	{
		string str = obj.name;
		for (int i = 0; i < str.length(); i++)
		{
			//returns first 3 characters
		}
	}*/
	void getperson()
	{
		cout << " Name : " << name <<endl<< " Age : " << age << endl<<" Gender : " << gender<<endl;
		cout << " Contact : " << contact << endl<<" Address : " << address << endl;
	}

	bool setFromFile(string iD)
	{
		bool check = false;
		
		ifstream file;
		file.open("Person.txt");
		string temp;
		while (!file.eof())
		{
			
			/*getline(file, temp);
			int index = temp.find(':');

			cout << index << " ";*/
			file >> temp;
			if (temp == iD)
			{
				string nm;
				getline(file, nm);
				getline(file, nm);
				

				int index=nm.find(':');
				
				name = nm.substr(index + 2);
				getline(file, nm);
				index = nm.find(':');
				gender = nm.substr(index + 2);

				getline(file, nm);
				index = nm.find(':');
				age = stoi(nm.substr(index + 2));


				getline(file,nm);
				 index = nm.find(':');
				contact = nm.substr(index + 2);
				

				getline(file, nm);
				index = nm.find(':');
				address = nm.substr(index + 2);

				check = true;

				break;



			}
		}

		if (check == true)
			return true;
		else
			return false;
		file.close();

	}

	
};

