
#include "stdafx.h"
#include "CppUnitTest.h"
#include"../Project1/account.h"
#include"accountReaderTEST.h"
#include"accountPROXY.h"

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


		TEST_METHOD(retdepositTEST)
		{
			Logger::WriteMessage("Return Deposit Test");

			accountReaderTEST* accntReaderTest = new accountReaderTEST();
			account accountUNDERTEST(accntReaderTest);

			accntReaderTest->setTESTdeposit(50);
			accountUNDERTEST.create_account();

			accountPROXY * accountUNDERTEST_PROXY = reinterpret_cast<accountPROXY *> ( & accountUNDERTEST);

			Assert::AreEqual( accountUNDERTEST_PROXY->deposit ,accountUNDERTEST.retdeposit(), L"Returned deposit and expected deposit are not equal");
		}

		TEST_METHOD(drawTEST)
		{
			Logger::WriteMessage("Draw From Deposit Test");

			int intialDeposit = 500;
			int drawAmnt = 50;
			int negDrawAmnt = -50;

			accountReaderTEST* accntReaderTest = new accountReaderTEST();
			account accountUNDERTEST(accntReaderTest);
			accountPROXY * accountUNDERTEST_PROXY = reinterpret_cast<accountPROXY *> (&accountUNDERTEST);

			accntReaderTest->setTESTdeposit(intialDeposit);
			accountUNDERTEST.create_account();
			accountUNDERTEST.draw(drawAmnt);

			Assert::AreEqual(intialDeposit-drawAmnt, accountUNDERTEST_PROXY->deposit,L"Drawn amount was not subtracted correctly from deposit");
		
			bool exceptionThrown = false;
			try
			{
				accountUNDERTEST.draw(negDrawAmnt);
			}
			catch(exception e)
			{
				string expectedEx = "Amount to be drawn can not be negative";
				exceptionThrown = true;
				string excDesc = e.what();
				Assert::AreEqual(expectedEx,excDesc ,L"Exception message wasn't as expected");
			}
			Assert::IsTrue(exceptionThrown, L"Exception wasn't thrown when input was negative");

			exceptionThrown = false;
			try
			{
				accountUNDERTEST.draw(intialDeposit - drawAmnt+1);
			}
			catch (exception e)
			{
				string expectedEx = "Amount to be drawn can not be bigger than deposit";
				exceptionThrown = true;
				string excDesc = e.what();
				Assert::AreEqual(expectedEx, excDesc, L"Exception message wasn't as expected");
			}
			Assert::IsTrue(exceptionThrown, L"Exception wasn't thrown when input was bigger than deposit");

		}

	};
}
