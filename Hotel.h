#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Hotel
{
	string name;
	string location;
	int floors;
	int no_employees;
	int totalRooms;
	int residents;
	double area;
	void setHotel();
	void getHotel()
	{
		cout << "Name: " << name << endl;
		cout << "Location: " << location << endl;
		cout << "Total Rooms: " << totalRooms << endl;
		cout << "Floors: " << floors << endl;
		cout << "Residents: " << residents << endl;
		cout << "No. of Employees: " << no_employees << endl;
		cout << "Area: " << area << endl;
	}
public:
	friend class Manager;
	Hotel()
	{
		fstream myFile;
		myFile.open("Hotel.txt", ios::in);
		int index=0;
		if (myFile.is_open())
		{
			getline(myFile, name);
			index = name.find(':');
			name = name.substr(index + 2);


			myFile >> totalRooms;
			cout << totalRooms << endl;
			myFile >> floors;
			cout << floors << endl;
			getline(myFile, location);
			index = location.find(':');
			/*location = location.substr(index + 2);*/
			
			myFile >> residents;
	
			myFile >> no_employees;

			myFile >> area;
	
		}
		myFile.close();

	}

	void getinfo()
	{
		getHotel();
	}
	
	~Hotel()
	{
		//cout << "Hotel is destroyed" << endl;
	}
};
void Hotel::setHotel()
{
	ofstream myFile;
	myFile.open("Hotel.txt");
	if (myFile.is_open())
	{
		cout << " ENTER NAME : " << endl;
		getline(cin, name);
		myFile << "Name: " << name << endl;
		cout << " ENTER LOCATION : " << endl;
		getline(cin, location);
		myFile << "Location: " << location << endl;
		cout << " ENTER TOTAL NO. OF EMPLOYEES : " << endl;
		cin >> no_employees;
		myFile << "Employees: " << no_employees << endl;
		cout << " ENTER TOTAL NO. OF FLOORS :  " << endl;
		cin >> floors;
		myFile << "Floors: " << floors << endl;
		cout << " ENTER TOTAL NO. OF ROOMS : " << endl;
		cin >> totalRooms;
		myFile << "Total Rooms: " << totalRooms << endl;
		cout << " ENTER NO. OF RESIDENTS : " << endl;
		cin >> residents;
		myFile << "Residents: " << residents << endl;
		cout << " ENTER TOTAL AREA : " << endl;
		cin >> area;
		myFile << "Area: " << area << endl;
	}
	myFile.close();
}
