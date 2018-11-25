#pragma once
#ifndef _SSTRING_H_
#include<iostream>
using namespace std;
#define MAXSTRING 255
typedef unsigned char SString[MAXSTRING+1];

//StrAssign ����һ���ַ���
void StrAssign(SString String, char * chars)
{
	if (strlen(chars) > MAXSTRING)
		return;
	else
	{
		String[0] = strlen(chars);
		for (int i = 1;i <= String[0];i++)
			String[i] = *(chars+i-1);
	}
}

//StrCopy ����һ���ַ���
void StrCopy(SString String,SString TString)
{
	int i;
	for (i = 0;i <=TString[0];i++)
		String[i] = TString[i];
}

//StrEmpty �жϴ��Ƿ�Ϊ��
string StrEmpty(SString String) 
{
	if (String[0] == 0)
		return "�ַ�����";
	else
		return "�ַ����ǿ�";
}

//StrCompare �Ƚ������ַ���
int StrCompare(SString string, SString tstring)
{
	int i;
	for (i = 1;i <= (int)string[0] && (int)tstring[0];++i)
		if (string[i] != tstring[i])
			return (int)(string[i] - tstring[i]);
	return string[0] - tstring[0];
}

//StrLength �����ַ�������
int StrLength(SString String)
{
	return (int)String[0];
}

//ClearString ���ַ������
void ClearString(SString String)
{
	String[0] = 0;
}

//ConCat ���������ַ���
void ConCat(SString string1,SString string2, SString tstring)
{
	int i = 0;

	if ((int)string1[0] + (int)string2[0] <= MAXSTRING)
	{
		for (i = 1;i <= (int)string1[0];i++)
			tstring[i] = string1[i];
		for (i = 1;i <= (int)string2[0];i++)
			tstring[(int)string1[0] + i] = string2[i];
		tstring[0] = string1[0] + string2[0];
	}
	else
	{
		for (i = 1;i <= string1[0];i++)
			tstring[i] = string1[0];
		for (i = 1;i <= MAXSTRING-string1[0];i++)
			tstring[string1[0] + i] = string2[i];
		tstring[0] = MAXSTRING;
	}
}

//SubString �����ַ�����һ��ָ�����ִ�
void SubString(SString Sub, SString string, int pos, int len)
{
	int i;
	if (pos<1 || pos>string[0] || len<0 || len>string[0] - pos + 1)
		return;
	else
	{
		for (i = 1;i <= len;i++)
			Sub[i] = string[pos + i - 1];
		Sub[0] = len;
	}
}

//Index ƥ���ַ���
int Index(SString string, SString Sub,int pos)
{
	int i, j;
	if (pos >= 1 && pos <= string[0])
	{
		i = pos;
		j = 1;
		while (i <= string[0] && j <= Sub[0])
		{
			if (string[i] == Sub[j])
			{
				++i;
				++j;
			}
			else
			{
				i = i - j + 2;
				j = 1;
			}
		}
		if (j > Sub[0])
			return i - Sub[0];
		else
			return 0;
	}
	else
		return 0;
}

//StrInsert �����ַ���
void StrInsert(SString string, int pos, SString Sub)
{
	int i;
	if (pos<1 || pos>string[0] + 1)
		return ;
	if ((int)string[0] + (int)Sub[0] <= MAXSTRING)
	{
		for (i = string[0];i >= pos;i--)
			string[i + Sub[0]] = string[i];
		for (i = pos;i<pos + Sub[0];i++)
			string[i] = Sub[i - pos + 1];
		string[0] = string[0] + Sub[0];
	}
	else
	{ 
		for (i = MAXSTRING;i <= pos;i--)
			string[i] = string[i - Sub[0]];
		for (i = pos;i<pos + Sub[0];i++)
			string[i] = Sub[i - pos + 1];
		string[0] = MAXSTRING;
	}
}

//StrDelete ɾ���ַ���
void StrDelete(SString string, int pos, int len)
{ 
	int i;
	if (pos<1 || pos>string[0] - len + 1 || len < 0)
		return;
	for (i = pos + len;i <= string[0];i++)
		string[i - len] = string[i];
	string[0] -= len;
}

//Replace �滻�ַ���
void Replace(SString string, SString Sub, SString Rstring)
{
	int i = 1; /* �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
	do
	{
		i = Index(string, Sub, i); /* ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
		if (i) /* ��S�д��ڴ�T */
		{
			StrDelete(string, i, StrLength(Sub)); /* ɾ���ô�T */
			StrInsert(string, i, Rstring); /* ��ԭ��T��λ�ò��봮V */
			i += StrLength(Rstring); /* �ڲ���Ĵ�V����������Ҵ�T */
		}
	} while (i);
}

//DestroyString �����ַ���
void DestroyString()
{

}

//Strprint ��ӡ�ַ���
void StrPrint(SString String)
{
	int i;
	for (i = 1;i <= String[0];i++)
		cout << String[i];
	cout << endl;
}

#endif // !_SSTRING_H_
