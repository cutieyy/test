#include"Binary_Search_Tree.h"

#include<fstream>
int main()
{
	BiTree Head,T,test;
	CreateBiTree(T);
	int data;
	int label;
	T->data = MAXSIGN;
	Head = T;

	ifstream in("array.txt");
	while (!in.eof())
	{
		in >> data;
		//Insert_Search_Tree(T, data);
		Insert_B_Node(T, data);
	}
	cout << endl;



/*	int count = 10;
	T->data = 5;
	Head = T;
	while (count--)
	{
		T = Head;
		if (count == 5)
			continue;
		Insert_Search_Tree(T,count);
	}
*/	
	

//	InOrderTraverse(Head);
//	cout << endl;
	LevelOrderTraverse(T);
	cout << "���" << BiTreeDepth(T) << endl;
/*	//ClearBiTree(T);
	PreOrderTraverse(Head);
	cout << endl;
	cout << "���" << BiTreeDepth(Head) << endl;

	test= LeftSibling(Head, 5);
	if (test != NULL)
		LevelOrderTraverse(test);
	else
		cout << "�ڵ㲻���ڣ�" << endl;


	test = Max_tree(Head);
	cout << "���ֵ��" << test->data << endl;
	test = Min_tree(Head);
	cout << "��Сֵ��" << test->data << endl;
	

	cout << "--------------------------------------------------" << endl;
	//LevelOrderTraverse(Head);
	//Delete_S_Node(Head, 17);
	LevelOrderTraverse(Head);

	cout << "--------------------------------------------------" << endl;
	cout<<"���߶Ȳ"<<Balance_Factor(Head)<<endl;

	cout << "--------------------------------------------------" << endl;
	Rotating_RL(Head, Head);
	LevelOrderTraverse(Head);
	cout << "���߶Ȳ" << Balance_Factor(Head) << endl;
*/
}