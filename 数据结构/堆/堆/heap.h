#pragma once
#ifndef _HEAP_H_
/*
此处写的堆使用的是数组形式构建的逻辑二叉树
特别地，为了能与习惯的左右子树计算相对应，并没有使用数组0的位置
代码中直接放弃了数组0的空间，成为浪费，实际中可以将数组0的位置记录成堆的heapsize，这样，无需传递对大小，简化程序
*/



#include <iostream>
using namespace std;

int Parent(int i)
{
	return i / 2;
}

int Left(int i)
{
	return 2*i;
}

int Right(int i)
{
	return i * 2+1;
}


void Max_Heapify(int *a,int i,int heap_size)
{
	int l, r,largest;
	l = Left(i);
	r = Right(i);
	if (l <= heap_size && a[l] > a[i])
		largest = l;
	else
		largest = i;
	if (r <= heap_size&& a[r] > a[largest])
		largest = r;
	if (largest != i)
	{
		int temp;
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		Max_Heapify(a,largest,heap_size);
	}

}

void Build_Max_Heap(int *a,int length,int heap_size)
{
	heap_size = length;
	int i;
	for(i=length/2;i>0;i--)
		Max_Heapify(a, i, heap_size);
}

void Heapsort(int *a, int length, int heap_size)
{
	Build_Max_Heap(a, length,heap_size);
	int i;
	for (i = length;i > 1;i--)
	{
		int temp;
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		heap_size = heap_size - 1;
		Max_Heapify(a, 1, heap_size);
	}
}

#endif // !_HEAP_H_

