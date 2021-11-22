#include "pch.h"
#include "CppUnitTest.h"
#include "E:\oop\LB_5.1_C\FuzzyNumber_Private.h"
#include "E:\oop\LB_5.1_C\FuzzyNumber_Private.cpp"
#include "E:\oop\LB_5.1_C\FuzzyNumber.cpp"
#include "E:\oop\LB_5.1_C\FuzzyNumber.h"
#include "E:\oop\LB_5.1_C\Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51C
{
	TEST_CLASS(UnitTest51C)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber_Private A(1, 1, 1);
			A.SetX(5);
			Assert::AreEqual(A.GetX(), 5.);

		}
	};
}
