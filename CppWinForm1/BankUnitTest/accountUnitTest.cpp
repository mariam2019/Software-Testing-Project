#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Project1/account.h"
#include"accountReaderTEST.h"
#include<string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankUnitTest
{
	TEST_CLASS(AccountUnitTest)
	{
		
	public:

		TEST_METHOD(create_accountTEST)
		{
			Logger::WriteMessage("What ever message");
			accountReaderTEST* accntReaderTest = new accountReaderTEST();
			account accountUNDERTEST(accntReaderTest);

			accntReaderTest->setnameTest("mariam");
		    accountUNDERTEST.create_account();
			Assert::AreEqual("mariam", accountUNDERTEST.getName());
			
			
		}

	};
}