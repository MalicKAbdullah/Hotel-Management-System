#pragma once
#include<iostream>
using namespace std;
class Transaction
{
	double bill;
	double user_payment;
public:
	void setBill(double bill)
	{
		this->bill = bill;

	}
	void setUserPayment(double user_payment)
	{
		this->user_payment = user_payment;
	}
	double getBill()
	{
		return bill;
	}
	double getUserPayment()
	{
		return user_payment;
	}
	bool computePayment()
	{
		if (user_payment == bill)
		{
			cout << endl<<"          ******** THANKS FOR BEING HERE. *********" << endl;
			return true;
		}
		if (user_payment < bill)
		{
			double due_amount = bill - user_payment;
			cout << endl<<"  REMAINING DUES ARE : " << due_amount << endl;
			return false;
		}
		if (user_payment > bill)
		{
			double remaining_amount = user_payment - bill;
			cout << endl<<"  YOUR REMAINING AMOUNT IS : " << remaining_amount << endl;
			return true;
		}
	}
};
