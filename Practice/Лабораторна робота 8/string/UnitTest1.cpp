#include "pch.h"
#include "CppUnitTest.h"
#include"..\Markow\Markow.h"
#include"..\Markow\String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(String_replace)
		{
			char a[] = "abab";
			String n(a);
			n.replace(0, 1);
			char b[] = "baab";
			for (int i = 0; i < n.get_size(); ++i) 
			{
				Assert::AreEqual(n.get_str()[i], b[i]);
			}
		}

		TEST_METHOD(String_get_size)
		{
			char a[] = "aaaa ";
			String n(a);
			Assert::AreEqual(n.get_size(), 4);
		}

		TEST_METHOD(Markow_srandard) 
		{
			string n = "aaaaabbbbb";
			char a[3] = "aa";
			char b[3] = "ba";
			char c[3] = "bb";
			string rez = algorithm_markowa_in_standard_type(n, a, b, c);
			char i1 = rez[0];
			char i2 = 'a';
			Assert::AreEqual(i1,i2);
		}
		
		TEST_METHOD(Markow_String) 
		{
 			char a[] = "mmmmnnnnn";
			String n(a);
			char h[3] = "mm";
			char j[3] = "nm";
			char k[3] = "nn";
			String b=markow_in_String(n, h, j, k);
			char rez[]="m";
			String r(rez);
			Assert::AreEqual(r.get_str()[0], b.get_str()[2]);
		}
	};
}
