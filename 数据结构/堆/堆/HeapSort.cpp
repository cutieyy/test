#include "heap.h"

int main()
{
	int a[11] = { 0,4,1,3,2,16,9,10,14,8,7 };
	Heapsort(a, 10, 10);
	for (int i = 1;i < 11;i++)
	{
		cout << a[i] << " ";
	}

}