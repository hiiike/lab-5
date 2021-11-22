#include "pch.h"
#include "CppUnitTest.h"
#include "E:\oop\lab5.1_B\lab5.1_B\FuzzyNumber.h"
#include "E:\oop\lab5.1_B\lab5.1_B\FuzzyNumber.cpp"
#include "E:\oop\lab5.1_B\lab5.1_B\Exception.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			FuzzyNumber A(3, 4, 6),
				B(1, 2, 7),
				C(0, 0, 0);

			C = A - B;
			Assert::AreEqual(C.GetX(), -4.0);

		}
	};
}