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

	virtual void readNumber(int& in )
	{
			cin >> in;
	}

	virtual void readChar(char& in)
	{
		cin >> in;
	}
	
};

