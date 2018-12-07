#pragma once
#include"account.h"
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>

class Bank
{
public:
	
	Bank()
	{
	}


	~Bank()
	{
	}

	//***************************************************************
	//    	function to write record in binary file
	//****************************************************************

	void write_account()
	{
		account ac;
		ofstream outFile;
		outFile.open("account.dat", ios::binary | ios::app);
		ac.create_account();
		outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		outFile.close();
	}

	//******************************************************************************
	//    	function to read specific record from file and display it given accnt no
	//******************************************************************************

	void display_sp(int n)
	{
		account ac;
		bool flag = false;
		ifstream inFile;
		inFile.open("account.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		cout << "\nBALANCE DETAILS\n";
		while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
		{
			if (ac.retacno() == n)
			{
				ac.show_account();
				flag = true;
			}
		}
		inFile.close();
		if (flag == false)
			cout << "\n\nAccount number does not exist";
	}


	//***************************************************************
	//    	function to modify record of file
	//****************************************************************

	void modify_account(int n)
	{
		bool found = false;
		account ac;
		fstream File;
		File.open("account.dat", ios::binary | ios::in | ios::out);
		if (!File)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		while (!File.eof() && found == false)
		{
			File.read(reinterpret_cast<char *> (&ac), sizeof(account));
			if (ac.retacno() == n)
			{
				ac.show_account();
				cout << "\n\nEnter The New Details of account" << endl;
				ac.modify();
				int pos = (-1)*static_cast<int>(sizeof(account));
				File.seekp(pos, ios::cur);
				File.write(reinterpret_cast<char *> (&ac), sizeof(account));
				cout << "\n\n\t Record Updated";
				found = true;
			}
		}
		File.close();
		if (found == false)
			cout << "\n\n Record Not Found ";
	}

	//***************************************************************
	//    	function to delete record of file
	//****************************************************************


	void delete_account(int n)
	{
		account ac;
		ifstream inFile;
		ofstream outFile;
		inFile.open("account.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		outFile.open("Temp.dat", ios::binary);
		inFile.seekg(0, ios::beg);
		while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
		{
			if (ac.retacno() != n)
			{
				outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
			}
		}
		inFile.close();
		outFile.close();
		remove("account.dat");
		rename("Temp.dat", "account.dat");
		cout << "\n\n\tRecord Deleted ..";
	}

	//*********************************************************************
	//    	function to display all accounts deposit list and their details
	//*********************************************************************

	void display_all()
	{
		account ac;
		ifstream inFile;
		inFile.open("account.dat", ios::binary);
		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
		cout << "====================================================\n";
		cout << "A/c no.      NAME           Type  Balance\n";
		cout << "====================================================\n";
		while (inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
		{
			ac.report();
		}
		inFile.close();
	}

	//***************************************************************
	//    	function to deposit and withdraw amounts
	//****************************************************************

	void deposit_withdraw(int n, int option)
	{
		int amt;
		bool found = false;
		account ac;
		fstream File;
		File.open("account.dat", ios::binary | ios::in | ios::out);
		if (!File)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}
		while (!File.eof() && found == false)
		{
			File.read(reinterpret_cast<char *> (&ac), sizeof(account));
			if (ac.retacno() == n)
			{
				ac.show_account();
				if (option == 1)
				{
					cout << "\n\n\tTO DEPOSITE AMOUNT ";
					cout << "\n\nEnter The amount to be deposited";
					cin >> amt;
					ac.dep(amt);
				}
				if (option == 2)
				{
					cout << "\n\n\tTO WITHDRAW AMOUNT ";
					cout << "\n\nEnter The amount to be withdraw";
					cin >> amt;
					int bal = ac.retdeposit() - amt;
					if ((bal < 500 && ac.rettype() == 'S') || (bal < 1000 && ac.rettype() == 'C'))
						cout << "Insufficience balance";
					else
						ac.draw(amt);
				}
				int pos = (-1)*static_cast<int>(sizeof(ac));
				File.seekp(pos, ios::cur);
				File.write(reinterpret_cast<char *> (&ac), sizeof(account));
				cout << "\n\n\t Record Updated";
				found = true;
			}
		}
		File.close();
		if (found == false)
			cout << "\n\n Record Not Found ";
	}


	//***************************************************************
	//    	INTRODUCTION FUNCTION
	//****************************************************************

	void intro()
	{
		cout << "\n\n\n\t  BANK";
		cout << "\n\n\tMANAGEMENT";
		cout << "\n\n\t  SYSTEM";
		cout << "\n\n\n\nMADE BY : your name";
		cout << "\n\nSCHOOL : your school name";
		cin.get();
	}
};