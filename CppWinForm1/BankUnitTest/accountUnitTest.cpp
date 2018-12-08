
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
			Logger::WriteMessage("Create Account Test");
			accountReaderTEST* accntReaderTest = new accountReaderTEST();
			account accountUNDERTEST(accntReaderTest);
			accountPROXY * accountUNDERTEST_PROXY = reinterpret_cast<accountPROXY *> (&accountUNDERTEST);

			accntReaderTest->setnameTest("mariam");
			accntReaderTest->setTESTaccno(55);
			accntReaderTest->setTESTdeposit(1500);
			accntReaderTest->setTypeTest('c');

		        accountUNDERTEST.create_account();

			Assert::AreEqual("mariam", accountUNDERTEST_PROXY->name,L"Name was not set correctly");
			Assert::AreEqual(55, accountUNDERTEST_PROXY->acno, L"Account number was not set correctly");
			Assert::AreEqual(1500, accountUNDERTEST_PROXY->deposit, L"Deposit was not set correctly");
			Assert::AreEqual('C', accountUNDERTEST_PROXY->type, L"Type was not set correctly");

			accntReaderTest->setTypeTest('C');
			accountUNDERTEST.create_account();
			Assert::AreEqual('C', accountUNDERTEST_PROXY->type, L"Type was not set correctly");

			accntReaderTest->setTypeTest('T');
			accountUNDERTEST.create_account();
			Assert::AreNotEqual('T', accountUNDERTEST_PROXY->type, L"User entered an invalid account type and the function didn't reject it");
		
			accntReaderTest->setTESTdeposit(-50);
			accountUNDERTEST.create_account();
			Assert::AreNotEqual(-50, accountUNDERTEST_PROXY->deposit, L"User entered an invalid initial deposit (<0) and the function didn't reject it");

			accntReaderTest->setTESTdeposit(450);
			accntReaderTest->setTypeTest('S');
			accountUNDERTEST.create_account();
			Assert::AreNotEqual(450, accountUNDERTEST_PROXY->deposit, L"User entered an invalid initial deposit for type S (<500) and the function didn't reject it");

			accntReaderTest->setTESTdeposit(850);
			accntReaderTest->setTypeTest('C');
			accountUNDERTEST.create_account();
			Assert::AreNotEqual(850, accountUNDERTEST_PROXY->deposit, L"User entered an invalid initial deposit for type C (<1000) and the function didn't reject it");

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
