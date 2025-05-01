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
			int actual = q.getanswer();

			Assert::AreEqual(3, actual);
		}
	};
}
