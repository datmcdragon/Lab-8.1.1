#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-8.1.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int i1 = 0, i2 = 0;
			bool b = SearchSim("This +-=", i1, i2);
			Assert::AreEqual(true, b);
		}
	};
}
