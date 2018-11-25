#pragma once
#ifndef _HEAP_H_
/*
�˴�д�Ķ�ʹ�õ���������ʽ�������߼�������
�ر�أ�Ϊ������ϰ�ߵ����������������Ӧ����û��ʹ������0��λ��
������ֱ�ӷ���������0�Ŀռ䣬��Ϊ�˷ѣ�ʵ���п��Խ�����0��λ�ü�¼�ɶѵ�heapsize�����������贫�ݶԴ�С���򻯳���
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

