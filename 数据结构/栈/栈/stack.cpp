#include"Stack.h"
int main()
{
	SqStack S;
	InitStack(S);
	int i = 10;
	while (i--)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "ջ�Ƿ�գ�" << StackEmpty(S) << endl;
		Push(S, i);
		cout<<GetTop(S)<<endl;
		StackTraverse(S);
		cout << "ջ���ȣ�" << StackLength(S) << endl;
	}
	/*i = 10;
	while (i--)
	{
		cout << "---------------------------------------------------------" << endl;
		cout << "ջ�Ƿ�գ�" << StackEmpty(S) << endl;
		cout << Pop(S) << endl;
		StackTraverse(S);
		cout << "ջ���ȣ�" << StackLength(S) << endl;
	}*/
	//ClearStack(S);
	//cout << "ջ�Ƿ�գ�" << StackEmpty(S) << endl;
	//DestoryStack(S);
}