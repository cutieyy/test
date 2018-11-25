#include"Stack.h"
int main()
{
	SqStack S;
	InitStack(S);
	int i = 10;
	while (i--)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "Õ»ÊÇ·ñ¿Õ£º" << StackEmpty(S) << endl;
		Push(S, i);
		cout<<GetTop(S)<<endl;
		StackTraverse(S);
		cout << "Õ»³¤¶È£º" << StackLength(S) << endl;
	}
	/*i = 10;
	while (i--)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "Õ»ÊÇ·ñ¿Õ£º" << StackEmpty(S) << endl;
		cout << Pop(S) << endl;
		StackTraverse(S);
		cout << "Õ»³¤¶È£º" << StackLength(S) << endl;
	}*/
	//ClearStack(S);
	//cout << "Õ»ÊÇ·ñ¿Õ£º" << StackEmpty(S) << endl;
	//DestoryStack(S);
}