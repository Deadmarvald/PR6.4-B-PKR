#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR6.4B/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT64B
{
	TEST_CLASS(UT64B)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* L = NULL;
			
            int start = 1, N = 3;
            Info value = 1;

            while (start <= N)
            {
                Elem* tmp = new Elem;
                tmp->info = value;
                if (L != NULL)
                {
                    Elem* T = L;
                    while (T->link != L)
                        T = T->link;
                    T->link = tmp;
                }
                else
                {
                    L = tmp;
                }
                tmp->link = L;
                start++;
            }

			increm(L, L, 1);

			Assert::AreEqual(L->info, 2);
		}
	};
}