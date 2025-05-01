#include "pch.h"
#include "CppUnitTest.h"
#include "../lr3/questionnaire.h"
#include <fstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

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
			of << "1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n";
			of.close();

			bool result = q.loadAnswersFromFile(filename);
			int actual = q.getAnswerFromMatrix(0, 1);

			Assert::IsTrue(result);
			Assert::AreEqual(2, actual);
		}

		TEST_METHOD(KeepAnswersInArrayTest) {
			questionnaire q;
			int questionNumber = 0;

			q.setAnswer(5);
			q.setAnswerToLine(questionNumber);
			int actual = q.getAnswerFromLine(0);

			Assert::AreEqual(5, actual);
		}
	};
}
