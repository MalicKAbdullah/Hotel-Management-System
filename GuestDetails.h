#pragma once
#include "Guest.h"
#include "Transaction.h"
double Per_Day_Room_Charges = 12000;
double Transport_Charges = 8000;
double Per_Member_Charges = 2000;

class GuestDetails :public Guest
{
	int members;
	int rooms;
	int transport;
	int days;
	bool cardHolder;
public:
	Transaction transac;
	GuestDetails()
	{
		members = rooms = transport = days = 0;
		cardHolder = true;
	}
	GuestDetails(string a, int c, int d, int e, int f) :Guest(a)
	{
		members = c;
		rooms = d;
		transport = e;
		days = f;
	}
	void setDetailsinFile(string id)
	{
		ofstream writer;
		writer.open("guestDetails.txt", ios::app);
		writer << endl;
		writer << guestid << "\t" << members << "\t\t" << rooms << "\t\t" << days << "\t\t" << transport << "\t\t" << cardHolder;
		writer.close();
	}

	void enterDetails(string id)
	{
		guestid = id;
		int b, c, d, e, f;
		cout << " Members : ";
		cin >> c;
		cout << " Rooms : ";
		cin >> d;
		cout << " Days : ";
		cin >> e;
		cout << " Transport Facility : ";
		cin >> f;
		cout << endl;
		Rooms r;
		if (d <= r.countAvailableRooms())
		{
			r.changeRoomStatus(d);
			r.showRoomsAllocatedtoGuest();
		}
		else
		{
			cout << " SORRY ! ROOMS ARE NOT AVAILIBLE " << endl;
		}
		cardHolder = isCardHolder(guestid);
		members = c;
		rooms = d;
		days = e;
		transport = f;

		setDetailsinFile(guestid);
	}


	bool getDetails(string id)
	{
		ifstream reader;
		int m;
		int r, d, t, c;
		bool check = false;
		
		reader.open("guestDetails.txt");
		string temp;
		while (!reader.eof())
		{
			reader >> temp;
			if (temp == id)
			{
				reader >> m >> r >> d >> t >> c;
				check = true;

			}

		}

		if (check == true)
		{
			cout << "\u001b[31;1m"<< "  GUEST DETAILS "<<"\u001b[0m "<< endl << endl;

			guestid = id;
			members = m;
			rooms = r;
			days = d;
			transport = t;
			cardHolder = c;

			cout << "  Guest ID : " << id << endl;
			cout << "  Members : ";
			cout << members << endl;
			cout << "  Rooms : ";
			cout << rooms << endl;
			cout << "  Days : ";
			cout << days << endl;
			cout << "  Transport Facility : ";
			cout << transport << endl;
			cout << "  Card Holder : ";
			cout << cardHolder << endl;

			return true;

		}
		else
		{
			return false;
		}
		reader.close();

	}
	double calculateBill()
	{
		double bill;
		/*per day room charges = 12000;
		transport charges = 8000;
		per member charges = 2000*/
		bill = (rooms * (days * Per_Day_Room_Charges))+(members*Per_Member_Charges);
		if (transport == 1)
		{
			bill += Transport_Charges;
		}
		if (cardHolder == 1)
			bill -= (bill / 10);
		cout << "\u001b[31;1m"<<"  Bill "<<"\u001b[0m= " << bill << endl;
		return bill;

	}
	int isCardHolder(string id)
	{
		ifstream reader;
		string holder;
		reader.open("card holders.txt");
		reader >> holder;
		cardHolder = 0;
		while (!reader.eof())
		{
			if (holder == id)
			{
				cardHolder = 1;
				break;
			}
			reader >> holder;
		}
		reader.close();
		if (cardHolder == 0)
			return 0;
		else
			return 1;
	}
};
