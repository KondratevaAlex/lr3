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
	};
}
