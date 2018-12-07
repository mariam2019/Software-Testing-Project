#pragma once
#include "../Project1/accountReader.h"

class accountReaderTEST :
public accountReader
{
	string nameTEST = "marina";
	int TESTaccno =-1;
	int TESTdeposit = -1;
	char TESTcharval='0';
public:
	void setnameTest(string n)
	{
		nameTEST = n;
	}
	void setTESTaccno(int Testval)
	{
		TESTaccno = Testval;
	}
	void setTESTdeposit(int Testval)
	{
		TESTdeposit = Testval;
	}
	void setTypeTest(char Testval)
	{
		TESTcharval = Testval;
	}
	void readName(char* name) override
	{
		
		strcpy(name, nameTEST.c_str());
	}

	void readAccNo(int& in) override
	{
		in = TESTaccno;
	}

	void readDeposit(int& in) override
	{
		in = TESTdeposit;
	}

	void readType(char& in) override
	{
		in = TESTcharval;
	}

};

