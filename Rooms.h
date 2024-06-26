#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Rooms
{
	int room[30];
	double price;
	bool roomStatus[30];
	int count;
	int* arr;
	int size; //rooms
public:
	Rooms()
	{
		count = 0;
		fstream roomFile;
		roomFile.open("Rooms.txt", ios::in);
		if (roomFile.is_open())
		{
			string line;
			getline(roomFile, line);
			int i = 0;
			while (roomFile >> room[i] >> roomStatus[i])
			{
				i++;
			}
		}
		roomFile.close();
		countAvailableRooms();
	}
	void getRooms()
	{
		ifstream roomFile;
		string line;
		roomFile.open("Rooms.txt");
		getline(roomFile, line);
		cout << line << endl << endl;
		roomFile.close();
		for (int i = 0; i < 30; i++)
		{
			cout << room[i] << "\t\t" << roomStatus[i] << endl;
		}
	}
	int countAvailableRooms()
	{
		count = 0;
		for (int i = 0; i < 30; i++)
		{
			if (roomStatus[i] == 0)
			{
				count++;
			}
		}		
		return count;
	}
	bool SearchRooms(int n)
	{
		bool f = true;
		//search a room
		fstream myfile;
		myfile.open("Rooms.txt", ios::in);
		string line;
		getline(myfile, line);
		cout << line << endl << endl;

		if (myfile.is_open())
		{

			for (int i = 0; i < 30; i++)
			{
				if (room[i] == n)
				{

					cout << room[i] << "\t\t" << roomStatus[i] << endl;

					f = true;
					break;

				}
				else

				{
					f = false;
				}
			}
			if (f == false)
			{
				cout << "Number not valid" << endl;

			}

		}
		myfile.close();
		return f;
	}
	void changeRoomStatus(int room_required)
	{
		int s = countAvailableRooms();
		if (room_required <= s)
		{
			//bool roomst[30];
			//when room is booked by the guest change the room status to not available
			ifstream myfile;
			ofstream file2;
			myfile.open("Rooms.txt", ios::in);
			file2.open("New.txt", ios::out);
			size = room_required;
			string line;
			getline(myfile, line);
			
			file2 << line << endl;
			getline(myfile, line);

			file2 << line ;
			arr = new int[room_required];
			int k = 0;
			for (int i = 0; i < 30; i++)
			{
				if (roomStatus[i] == 0)
				{
					if (k < room_required)
					{

						arr[k] = room[i];;
						roomStatus[i] = true;
					
					}
					k++;
					file2 << endl<<room[i] << "\t\t" << roomStatus[i];
				}
				else
				{
					file2 << endl<<room[i] << "\t\t" << roomStatus[i] ;
				}
			}
			file2.close();
			myfile.close();
			remove("Rooms.txt");
			
		
			rename("New.txt", "Rooms.txt");
			
		}
		else
		{
			cout << "rooms not available" << endl;
		}
		/*showRoomsAllocatedtoGuest(room_required);*/
	}
	void AllocatedRooms()
	{
		//print allocated rooms
		for (int i = 0; i < 30; i++)
		{
			if (roomStatus[i] == 1)
			{
				cout << room[i] << " is allocated" << endl;
			}
		}
	}
	void EmptyTheRoom(int* arr, int k)
	{
		//when a guest leaves change room status to available
		bool roomst[30];
		ifstream roomFile;
		ofstream newFile;
		roomFile.open("Rooms.txt", ios::in);
		newFile.open("New.txt", ios::out);
		string line;
		getline(roomFile, line);
		newFile << line << endl;
		getline(roomFile, line);
		newFile << line << endl;
		cout << "array from the main" << endl;

		for (int j = 0; j < k; j++)
		{
			
			cout << arr[j] << endl;
		}
		int a = 0;
		for (int i = 0; i < 30; i++)
		{
			if (room[i] != arr[a])
			{
				newFile << room[i] << "\t\t" << roomStatus[i] << endl;
			}

			else
			{
				if (a < k)
				{
					if (roomStatus[i] == 1)
					{
						roomst[i] = false;
						newFile << room[i] << "\t\t" << roomst[i] << endl;
					}
					a++;
				}
			}
		}
		newFile.close();
		roomFile.close();
		remove("Rooms.txt");
	
	
		rename("New.txt", "Rooms.txt");

	}

	bool checkavailibility(int n)
	{
		if (n < count)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void showRoomsAllocatedtoGuest()
	{
		cout << " THE ROOMS ALLOCATED TO GUEST " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << " ROOM NO : " << "\u001b[31;1m" <<arr[i]<<"\u001b[0m" << endl;
		}
		cout << endl;
	}
	//~Rooms()
	//{
	//	//this variable will be received from main and file will be updated according to it.
	//	changeRoomStatus(/*int rooms_required*/);
	//}
};
