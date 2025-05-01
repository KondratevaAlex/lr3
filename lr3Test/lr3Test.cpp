#include "pch.h"
#include "CppUnitTest.h"
#include "../lr3/questionnaire.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lr3Test
{
	TEST_CLASS(lr3Test)
	{
	public:
		
		TEST_METHOD(CreateClassTest)
		{
			questionnaire* q = new questionnaire;
			Assert::IsNotNull(q);
		}

		TEST_METHOD(SetAndGetAnswerTest) {
			questionnaire q;

			q.setAnswer(3);
			int actual = q.getAnswer();

			Assert::AreEqual(3, actual);
		}

		TEST_METHOD(LoadAnswersFromFileTest) {
			questionnaire q;

			string filename = "test";
			ofstream of(filename);
			out << "1 2\n3 4\n";
			of.close();

			int testMatr[2][2];
			bool actual = loadAnswersFromFile(filename, testMatr);

			Assert::IsTrue(actual);
			Assert::AreEqual(2, testMatr[0][1]);
		}
	};
}
