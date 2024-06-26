#pragma once
#include <fstream>
#include "Person.h"


class Guest : public Person
{
protected:
	string guestid;

public:

	Guest()
	{
		guestid = " ";
	}

	Guest(string a)
	{
		guestid = a;
	}

	void setguestid(string a)
	{
		string temp = "g_";
		string sub = a.substr(0, 3);

		for(int i=0;i<3;i++)
			if (sub[i] >= 'A' && sub[i] <= 'Z')
				sub[i] += 32;
		string x;

		ifstream file;
		file.open("guestIDs.txt");
		
		string t;
		while (!(file.eof()))
		{
			file >> t;

		}
		x = (t.substr(5));
		int tem = stoi(x) + 1;
		x = to_string(tem);


		guestid = temp + sub + '0'+x;

		ofstream setter;
		setter.open("guestIDs.txt", ios::app);
		setter << endl;
		setter << guestid;
		setter.close();
	}
	void setguest(string a)
	{
		setFromFile(a);
		
		
	}
	void setNewGuest()
	{
		setperson();
		setguestid(name);


		ofstream file;
		file.open("Person.txt", ios::app);
		file << endl<<endl;

		file << "Guest_Id : " << guestid << endl;
		file << "Name : " << name << endl;
		file << "Gender : " << gender<< endl;
		file << "Age : " << age << endl;
		file << "Contact : " << contact<< endl;
		file << "Address : " << address;


		
	}

	string getguestID()
	{
		return guestid;
	}

	void getguest()
	{
		cout << "GUEST ID : " << guestid << endl;
		getperson();
		
	}


};
