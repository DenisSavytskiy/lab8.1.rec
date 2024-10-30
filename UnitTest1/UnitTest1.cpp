#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№8.1.рек/AP_Lab№8.1.рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(RecursiveTests)
    {
    public:
        TEST_METHOD(TestCount)
        {
            char str[] = "while doing while loop while";
            int result = Count(str, 0);
            Assert::AreEqual(3, result);
        }

        TEST_METHOD(TestChange)
        {
            char str[] = "while doing while loop while";
            char dest[100] = "";
            char* result = Change(dest, str, dest, 0);
            Assert::AreEqual("*** doing *** loop ***", result);
        }
    };
}