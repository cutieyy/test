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
	cout << "树深：" << BiTreeDepth(T) << endl;
/*	//ClearBiTree(T);
	PreOrderTraverse(Head);
	cout << endl;
	cout << "树深：" << BiTreeDepth(Head) << endl;

	test= LeftSibling(Head, 5);
	if (test != NULL)
		LevelOrderTraverse(test);
	else
		cout << "节点不存在！" << endl;


	test = Max_tree(Head);
	cout << "最大值：" << test->data << endl;
	test = Min_tree(Head);
	cout << "最小值：" << test->data << endl;
	

	cout << "--------------------------------------------------" << endl;
	//LevelOrderTraverse(Head);
	//Delete_S_Node(Head, 17);
	LevelOrderTraverse(Head);

	cout << "--------------------------------------------------" << endl;
	cout<<"树高度差："<<Balance_Factor(Head)<<endl;

	cout << "--------------------------------------------------" << endl;
	Rotating_RL(Head, Head);
	LevelOrderTraverse(Head);
	cout << "树高度差：" << Balance_Factor(Head) << endl;
*/
}