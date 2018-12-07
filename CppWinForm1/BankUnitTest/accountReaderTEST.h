#pragma once
#include "../Project1/accountReader.h"

class accountReaderTEST :
public accountReader
{
	string nameTEST = "marina";
	int TESTintval=-1;
	char TESTcharval='0';
public:
	void setnameTest(string n)
	{
		nameTEST = n;
	}
	void setintTest(int Testval)
	{
		TESTintval = Testval;
	}
	void setcharTest(char Testval)
	{
		TESTcharval = Testval;
	}
	void readName(char* name) override
	{
		
		strcpy(name, nameTEST.c_str());
	}

	void readNumber(int& in) override
	{
		in = TESTintval;
	}

	void readChar(char& in) override
	{
		in = TESTcharval;
	}

};

