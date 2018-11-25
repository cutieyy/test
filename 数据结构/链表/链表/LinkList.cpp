#include "LinkList.h"
int main()
{
	LinkList L;
	InitList(L);
	int i = 0;
	while (i < 10) {
		ListInsert(L,1,i);
		i++;
	}
	ListTraverse(L);

	ListReverse(L);
	ListTraverse(L);

	i = 0;
	while (i < 10) {
		cout << i + 1 << ":" << GetELement(L, i+1) << endl;
		i++;
	}

	
	cout<<LocateElement(L, 5) << endl;

	cout << PriorElement(L, 5) << endl;

	cout << NextElement(L, 5) << endl;

	cout << "������Ϊ��" << ListLength(L) << endl;
	//ListDelete(L,1);
	//DestroyList(L);
	if (ListEmpty(L) == 0)
		cout << "����ǿ�" << endl;
	else
		cout << "�����" << endl;

	ClearList(L);

	if (ListEmpty(L) == 0)
		cout << "����ǿ�" << endl;
	else
		cout << "�����" << endl;

	ListTraverse(L);
	return 0;
}