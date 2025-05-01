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

		TEST_METHOD(CountPossibleIllnessTest) {
			questionnaire q;

			string filename = "test";
			ofstream of(filename);
			of << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n";
			of.close();

			for (int i = 0; i < 15; i++) {
				q.setAnswer(1);
				q.setAnswerToLine(i);
			}

			q.loadAnswersFromFile(filename);

			q.countPossibleIllness();

			int actual = q.getPossibleIllnessValue(0);
			Assert::AreEqual(15, actual);
		}

		TEST_METHOD(SortDiagnosesTest) {
			questionnaire q;

			string filename = "test";
			ofstream of(filename);
			of << "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4\n1 2 3 4 5 1 2 3 4 5 1 2 3 4 5\n2 3 4 5 1 2 3 4 5 1 2 3 4 5 1\n3 4 5 1 2 3 4 5 1 2 3 4 5 1 2\n4 5 1 2 3 4 5 1 2 3 4 5 1 2 3\n5 1 2 3 4 5 1 2 3 4 5 1 2 3 4";
			of.close();

			for (int i = 0; i < 15; i++) {
				q.setAnswer(1);
				q.setAnswerToLine(i);
			}

			q.loadAnswersFromFile(filename);
			q.countPossibleIllness();

			q.sortDeseases();

			int actual = q.getMainDiagnose();
			Assert::AreEqual(0, actual);
		}
	};
}
