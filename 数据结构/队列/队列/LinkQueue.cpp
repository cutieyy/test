#include"LinkQueue.h"
#include"SqQueue.h"
#include<string>
int main()
{
	//LinkQueue LQ;
	SqQueue LQ;
	InitQueue(LQ);
	cout<<QueueEmpty(LQ)<<endl;
	int i = 10;
	while (i--)
	{
		EnQueue(LQ, i);
	}
	cout<<QueueLength(LQ)<<endl;
	QueueTraverse(LQ);
	
	i = 5;
	while (i--)
	{
		DeQueue(LQ);
	}
	cout << QueueLength(LQ) << endl;
	QueueTraverse(LQ);

	ClearQueue(LQ);
	cout << QueueEmpty(LQ) << endl;
	DesreoyQueue(LQ);
}