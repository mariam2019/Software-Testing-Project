#pragma once
#include<iostream>
using namespace std;


class accountReader
{
	

public:
	
	virtual void readName(char* name)
	{
	
			cin.ignore();
			cin.getline(name, 50);
		
	}

	virtual void readDeposit(int& in )
	{
			cin >> in;
	}

	virtual void readAccNo(int& in)
	{
		cin >> in;
	}

	virtual void readType(char& in)
	{
		cin >> in;
	}
	
};

