#pragma once

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include"accountReader.h"

using namespace std;

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
	accountReader* accntReader;
public:
	
	account(accountReader* accntRead=new accountReader())
	{
		accntReader = accntRead;
	}

	
	char* getName()
	{
		return name;
	}
	
	void create_account()//function to get data from user
	{
		cout << "\nEnter The account No. : ";
		accntReader->readAccNo(acno);
		cout << "\n\nEnter The Name of The account Holder : ";
		accntReader->readName(name);
		cout << "\nEnter Type of The account (C/S) : ";
		accntReader->readType(type);
		type = toupper(type);
		cout << "\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
		accntReader->readDeposit(deposit);
		cout << "\n\n\nAccount Created..";
	}

	void show_account() const	//function to show data on screen
	{
		cout << "\nAccount No. : " << acno;
		cout << "\nAccount Holder Name : ";
		cout << name;
		cout << "\nType of Account : " << type;
		cout << "\nBalance amount : " << deposit;
	}

	void modify()	//function to add new data
	{
		cout << "\nAccount No. : " << acno;
		cout << "\nModify Account Holder Name : ";
		cin.ignore();
		cin.getline(name, 50);
		cout << "\nModify Type of Account : ";
		cin >> type;
		type = toupper(type);
		cout << "\nModify Balance amount : ";
		cin >> deposit;
	}

	void dep(int x)	//function to accept amount and add to balance amount
	{
		deposit += x;
	}

	void draw(int x)	//function to accept amount and subtract from balance amount
	{
		if(x<0)
			throw std::invalid_argument("Amount to be drawn can not be negative");
		if(x>deposit)
			throw std::invalid_argument("Amount to be drawn can not be bigger than deposit");

		deposit -= x;
	}

	void report() const	//function to show data in tabular format
	{
		cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
	}

	int retacno() const	//function to return account number
	{
		return acno;
	}

	int retdeposit() const	//function to return balance amount
	{
		return deposit;
	}


	char rettype() const //function to return type of account
	{
		return type;
	}



};         //class ends here

