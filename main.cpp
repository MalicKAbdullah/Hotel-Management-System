#include "User.h"
#include "Employee.h"
#include "Budget.h"
#include <Windows.h>



void empFunctionalities(string employeeid);
void managerFunctionalities(string managerid);
bool UserAuthentication();
void interface1();
int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);


	interface1();
	UserAuthentication();



}
bool UserAuthentication()
{
	string ch;
	cout << "  THE "<<red<<"AUTHORITY"<<reset<< " OF THE USER.\n";
	do
	{
		cout << "  1. MANAGER \n  2. EMPLOYEE \n ";
		cout << "\u001b[31;1m" << " ENTER YOUR CHOICE : " << "\u001b[0m";
		cin >> ch;

		if (!(ch == "1" || ch == "2"))
		{
			cout << endl << " ENTER INPUT AGAIN." << endl ;
			cout << endl;
		}
	} while (!(ch == "1" || ch == "2"));
	cout << endl;

	if (ch == "1")
	{
		User M;
		cin.ignore();
		string id=M.setManager();

		if (M.validate_manager())
		{

			system("CLS");
			managerFunctionalities(id);

		}

		else
		{
			cout << "  INVALID USER " << endl;
			cout << endl;
			UserAuthentication();
			return false;
		}



	}

	if (ch == "2")
	{
		string id;
		cin.ignore();
		cout << " \u001b[34;1m ENTER EMPLOYEE ID : \u001b[0m";
		getline(cin, id);

		User E;
		E.setemployeeid(id);

		if (E.validate_employee())
		{
			Employee e;
			e.setemployee(id);

			system("CLS");
			empFunctionalities(id);
		}

		else
		{
			cout << "  INVALID USER " << endl;
			cout << endl;
			UserAuthentication();
			return false;
		}




	}

}
void interface1()
{
	
	cout << endl << endl;
	for (int i = 0; i < 50; i++)
		cout <<' ';
	for (int i = 0; i < 76; i++)
		cout << "\u001b[31;1m" <<'*'<<"\u001b[0m";
	cout << endl;

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 50; i++)
			cout << ' ';

		for (int i = 0; i < 54; i++)
		{
			if (i == 0)
				cout << "\u001b[31;1m" << '*' << "\u001b[0m";
			else if (i > 0 && i <= 24)
				cout << ' ';
			else if (i == 25)
			{
				if(j==7)
					cout<<"\u001b[1m"<<"HOTEL MANAGEMENT SYSTEM";
				else
				{
					for(int i=0;i<23;i++)
						cout<<' ';
				}

			}
			
			else if (i > 25 && i < 53)
				cout << ' ';
			else
				cout << "\u001b[31;1m" << '*' << "\u001b[0m"<<endl;
		}

	}

	for (int i = 0; i < 50; i++)
		cout << ' ';
	for (int i = 0; i < 76; i++)
		cout << "\u001b[31;1m" << '*' << "\u001b[0m";

	/*cout << endl;
	for (int i = 0; i < 50; i++)
		cout << ' ';
	for (int i = 0; i < 76; i++)
		cout <<'*';*/
	cout<< endl;

	for (int i = 0; i < 60; i++)
		cout << ' ';
	for (int i = 0; i < 56; i++)
		cout << '*';
	cout << endl<<endl<<endl;
	
}

void empFunctionalities(string employeeid)
{
	//employee id validation
	string emp;
	cout << endl << endl << endl << endl;
	cout << red<<"                                                         **************** " << blue << "EMPLOYEE FUNCTIONALITIES " << red << "**************** "<<reset<<endl<<endl << endl;
	cout << red << " 01." << reset << " ADD A NEW GUEST"<< endl;
	cout << red << " 02." << reset << " VIEW YOUR DETAILS" << endl; 
	cout << red << " 03." << reset << " SEARCH FOR A GUEST" << endl ;
	cout << red << " 04." << reset << " CALCULATE THE BILL OF A GUEST" << endl ;
	cout << red << " 05." << reset << " SHOW HOTEL CHARGES DETAILS" << endl ;
	cout << red << " 06." << reset << " ACCEPT & VALIDATE GUEST BILL " << endl ;

	cout << red << " 99." << reset << " EXIT"<<endl<<endl;
	cout <<blue<< " ENTER YOUR CHOICE : "<<reset;
	cin >> emp;
	cin.ignore();
	system("CLS");
	if (emp == "1")
	{
		cout << endl <<red<< "                                                            ************** " << blue << "ADD GUEST DETAILS " << red << "*************" << endl <<reset<< endl;
		GuestDetails guest;
		guest.setNewGuest();
		guest.enterDetails(guest.getguestID());
		cout << blue<<" GUEST HAS BEEN ADDED SUCCESSFULLY."<<reset << endl;
		cout << endl;
		empFunctionalities(employeeid);
	

	}
	else if (emp == "2")
	{
		cout << endl <<red<< "                                                            ****************" << blue << " EMPLOYEE DETAILS" << red << " ****************" << endl << reset<<endl;

		Employee employee;
		employee.setemployee(employeeid);
		employee.getemployee();


		empFunctionalities(employeeid);

	}
	else if (emp == "3")
	{
		cout << endl<<red << "                                                    ****************" << blue << " SEARCHING FOR GUEST IN OUR DATABASE" << red << " ****************" <<reset<< endl << endl;

		string id;
		cout << " ENTER GUEST ID : ";
		getline(cin, id);
		Person obj;
		cout << endl;
		if (obj.setFromFile(id))
			obj.getperson();
		else
			cout << blue<< " GUEST NOT FOUND.\n"<<reset;
		cout << endl<<endl;
		empFunctionalities(employeeid);
		// search guest
	}
	else if (emp == "4")
	{
		cout << endl <<red<< "                                                       **************** "<<blue<<"CALCULATING THE GUEST BILL "<<red<<" ***************" << endl<<reset << endl;

		string tempid;
		cout << " ENTER GUEST ID : ";
		getline(cin, tempid);
		cout << endl;
		GuestDetails guestdetails;
		if (guestdetails.getDetails(tempid))
		{
			cout << endl;
			guestdetails.calculateBill();

		}
		else
			cout << blue<<"GUEST NOT FOUND.\n"<<reset;
		empFunctionalities(employeeid);

	}

	else if (emp == "5")
	{
		cout << endl<<red<< "                                                        ***************** " << blue << "HOTEL CHARGES DETAILS" << red << " **************" << endl <<reset<< endl;

		cout << endl;
		cout << blue<<" PER DAY ROOM CHARGES : " <<reset<< Per_Day_Room_Charges << endl;
		cout <<red<< " CHARGES PER MEMBER : " << reset<<Per_Member_Charges << endl;
		cout << blue<<" TRANSPORT CHARGES : " << reset<<Transport_Charges << endl;
		cout << red<<" DISCOUNT ON CARDHOLDERS : " <<reset<< "10% OF THE TOTAL BILL" << endl;

		empFunctionalities(employeeid);
	}

	else if (emp == "6")
	{
		cout << endl << red<<"                                                        ***************** " << blue << "ACCEPT & VALIDATE GUEST BILL" << red << " **************" << reset<<endl << endl;

		string tempid;
		cout << " ENTER GUEST ID : ";
		getline(cin, tempid);
		cout << endl;
		GuestDetails guestdetails;
		if (guestdetails.getDetails(tempid))
		{


			cout << endl;
			double bill = guestdetails.calculateBill();

			guestdetails.transac.setBill(bill);
			double payment;
			cout << blue<<"  ENTER CUSTOMER PAYMENT : "<<reset;
			cin >> payment;

			guestdetails.transac.setUserPayment(payment);

			if (guestdetails.transac.computePayment())
			{
				Employee temp;
				temp.budgetupdate.add(bill);
			}
		}
		else
		{
			cout << blue << " GUEST NOT FOUND.\n" << reset;


		}

		empFunctionalities(employeeid);
	}


	else if(emp=="99")
	{
		cout << endl << endl << endl <<red<< "                                   ******************** " << blue << "YOU ARE SUCCESSFULLY SIGNED OUT." << red << " ************************" <<reset<< endl;

	}
	else 
	{
		cout <<endl<<red<<" ERROR ! "<<blue<<"INVALID INPUT" << endl<<reset<<endl;
		empFunctionalities(employeeid);
	}
}
void managerFunctionalities(string id)
{
	//manager id validation
	string man;
	cout << endl << endl << endl << endl;
	cout << red << "                                                            ************* " << blue << "MANAGER FUNCTIONALITIES" << red << " **************** " << endl << endl << endl << reset;
	cout << red << " 01." << reset << " CHANGE YOUR USERNAME " << endl;
	cout << red << " 02." << reset << " CHANGE YOUR PASSWORD " << endl;
	cout << red << " 03." << reset << " VIEW YOUR DETAILS " << endl;
	cout << red << " 04. " << reset << "VIEW HOTEL DETAILS" << endl;
	cout << red << " 05." << reset << " VIEW EMPLOYEE DETAILS" << endl;
	cout << red << " 06." << reset << " VIEW PERSON DETAILS OF THE HOTEL" << endl;
	cout << red << " 07." << reset << " CHANGE AN EMPLOYEE SALARY" << endl;
	cout << red << " 08." << reset << " CHANGE THE SALARY STATUS OF AN EMPLOYEE" << endl;
	cout << red << " 09." << reset << " PAY AN EMPLOYEE SALARY" << endl;
	cout << red << " 10." << reset << " ADD A NEW EMPLOYEE" << endl;
	cout << red << " 11." << reset << " VIEW BUDGET DETAILS" << endl;

	cout <<red<< " 99. "<<reset<<"EXIT" << endl << endl;
	cout << blue<<"ENTER YOUR CHOICE : "<<reset;

	cin >> man;
	cin.ignore();

	system("CLS");
	if (man == "1")
	{

		cout << endl << endl << endl << endl;
		cout << red << "                                                             *************** " << blue << "CHANGE USERNAME " << red << "**************** " << endl << endl << endl << reset;
		Manager m;

		m.changeUsername();
		cout << endl << "  USERNAME HAS BEEN CHANGED SUCCESSFULLY" << endl;
		managerFunctionalities(id);

	}
	else if (man == "2")
	{

		cout << endl << endl << endl << endl;
		cout << red << "                                                              *************** " << blue << " PASSWORD " << red << "**************** " << endl << endl << endl << reset;
		Manager manager;
		manager.changePassword();
		cout << endl << "  PASSWORD HAS BEEN CHANGED SUCCESSFULLY" << endl;
		managerFunctionalities(id);
	}
	else if (man == "4")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                              *************** " << blue << "HOTEL DETAILS" << red << " **************** " << endl << endl << endl << reset;

		Manager m;
		m.HotelDetails();
		managerFunctionalities(id);
	}
	else if (man == "5")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                              *************** " << blue << "EMPLOYEE DETAILS" << red << " **************** " << endl << endl << endl << reset;

		Manager m;
		m.EmployeeDetails();
		managerFunctionalities(id);
	}
	else if (man == "3")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                              *************** " << blue << "YOUR DETAILS " << red << "**************** " << endl << endl << endl << reset;

		Manager m;
		m.getmanager();
		managerFunctionalities(id);


	}
	else if (man == "6")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                           ************ " << blue << "PERSON DETAILS OF YOUR HOTEL " << red << "************* " << endl << endl << endl << reset;

		Manager m;
		m.PersonDetails();
		managerFunctionalities(id);
	}
	else if (man == "7")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                           ************ " << blue << " SALARY OF AN EMPLOYEE" << red << " ************* " << endl << endl << endl << reset;

		cout << "  ENTER EMPLOYEE ID : ";
		string i;
		getline(cin, i);

		Employee obj;
		if (obj.checkemployee(i))
		{

			int sal;
			do
			{


				cout << "  ENTER AMOUNT OF SALARY : ";

				cin >> sal;
				if (sal < 0)
				{
					cout << "  ENTER VALID AMOUNT.\n";
				}
			} while (sal < 0);

			Manager m;
			m.setSalary(i, sal);

			cout << blue << "  SALARY HAS BEEN CHANGED SUCCESSFULLY." << reset << endl;
		}
		else
			cout << blue << "  EMPLOYEE NOT FOUND.\n" << reset << endl;

		managerFunctionalities(id);
	}
	else if (man == "8")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                           ************ " << blue << "SALARY STATUS OF AN EMPLOYEE" << red << " ************* " << endl << endl << endl << reset;

		cout << "  ENTER EMPLOYEE ID : ";
		string i;
		getline(cin, i);

		Employee obj;
		if (obj.checkemployee(i))
		{


			int temp;
			do
			{


				cout << "  ENTER SALARY STATUS (0/1) : ";
				cin >> temp;
				if (temp != 0 && temp != 1)
				{
					cout << "  ENTER VALID INPUT (0/1).\n";
				}
			} while (temp != 0 && temp != 1);

			bool sal;
			if (temp == 0)
				sal = false;
			else
				sal = true;

			Manager m;
			m.setSalaryStatus(i, sal);

			cout << blue << "  SALARY STATUS HAS BEEN CHANGED SUCCESSFULLY." << reset;
		}
		else
			cout << blue << "  EMPLOYEE NOT FOUND.\n" << reset << endl;

		managerFunctionalities(id);
	}
	else if (man == "9")
	{

		cout << endl << endl << endl << endl;
		cout << red << "                                                           ************ " << blue << "PAY EMPLOYEE SALARY " << red << "************* " << endl << endl << endl << reset;

		cout << "  ENTER EMPLOYEE ID : ";
		string i;
		getline(cin, i);
		
		Employee obj;
		if (obj.checkemployee(i))
		{


			int sal;
			do
			{
				cout << "  ENTER AMOUNT OF SALARY : ";

				cin >> sal;
				if (sal < 0)
				{
					cout << "  ENTER VALID AMOUNT.\n";
				}
			} while (sal < 0);

			Manager m;
			m.setSalaryPaid(i, sal);

			cout << blue << "  SALARY HAS BEEN TRANSFERED TO THE EMPLOYEE SUCCESSFULLY." << reset;
		}
		else
			cout << blue << "  EMPLOYEE NOT FOUND.\n" << reset << endl;

		managerFunctionalities(id);
	}

	else if (man == "10")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                           ************ " << blue << "ADD NEW EMPLOYEE" << red << " ************* " << endl << endl << endl << reset;

		Manager mg;
		mg.setNewEmployee();

		cout << blue << " NEW EMPLOYEE HAS BEEN ADDED SUCCESSFULLY." << endl << reset;
		managerFunctionalities(id);
	}

	else if (man == "11")
	{
		cout << endl << endl << endl << endl;
		cout << red << "                                                           ************" << blue << " HOTEL BUDGET DETAILS " << red << "************* " << endl << endl << endl << reset;

		Manager m;
		m.BudgetDetails();

		managerFunctionalities(id);
	}
	else if (man == "99")
	{
		cout << red << endl<<endl<<endl<<"                                   ********************" << blue << " YOU ARE SUCCESSFULLY SIGNED OUT" << red << " ************************" << endl<<reset;
	
	}
	else
	{
		cout << blue<<"ERROR ! "<<red<<"INVALID INPUT" << endl;
		managerFunctionalities(id);
	}
}