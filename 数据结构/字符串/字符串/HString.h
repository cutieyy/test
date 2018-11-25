#pragma once
#ifndef _HSTRING_H_
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct
{
	char *ch;
	int length;
}HString;


//StrAssign ����һ���ַ���
void StrAssign(HString &string,char *chars)
{
	int i, j;
	i = strlen(chars);
	if (!i)
	{
		string.ch = NULL;
		string.length = 0;
	}
	else
	{
		string.ch = (char*)malloc(sizeof(char)*i);
		if (!string.ch)
			exit(-1);
		for (j = 0;j < i;j++)
			string.ch[j] = chars[j];
		string.length = i;
	}
}
//StrCopy ����һ���ַ���
void StrCopy(HString &TString, HString String)
{
	int i, j;
	TString.ch = (char*)malloc(sizeof(char)*String.length);
	if (!TString.ch)
		exit(-1);
	else
	{
		for (i = 0;i < String.length;i++)
			TString.ch[i] = String.ch[i];
		TString.length = String.length;
	}
}

//StrEmpty �жϴ��Ƿ�Ϊ��
string StrEmpty(HString String)
{
	if (String.length == 0)
		return "�ַ�����";
	else
		return "�ַ����ǿ�";
}

//StrCompare �Ƚ������ַ���
int StrCompare(HString string,HString tstring)
{
	int i;
	for (i = 0;i<string.length&&i<tstring.length;++i)
		if (string.ch[i] != tstring.ch[i])
			return string.ch[i] - tstring.ch[i];
	return string.length - tstring.length;
}

//StrLength �����ַ�������
int StrLength(HString String)
{
	return String.length;
}

//ClearString ���ַ������
void ClearString(HString &String)
{
	String.ch = NULL;
	String.length = 0;
}

//ConCat ���������ַ���
void ConCat(HString string1, HString string2, HString &tstring)
{
	int i;
	tstring.length = string1.length + string2.length;
	tstring.ch = (char*)malloc(sizeof(char)*tstring.length);
	for (i = 0;i < string1.length;i++)
		tstring.ch[i] = string1.ch[i];
	for (i = 0;i < string2.length;i++)
		tstring.ch[string1.length + i] = string2.ch[i];
}
//SubString �����ַ�����һ��ָ�����ִ�
void SubString(HString &Sub, HString string, int pos, int len)
{
	int i;
	if (pos<0 || pos>string.length || len<0 || len>string.length - pos + 1)
		return;
	else
	{
		Sub.ch = (char*)malloc(sizeof(char)*len);
		for (i = 0;i < len;i++)
			Sub.ch[i] = string.ch[pos + i - 1];
		Sub.length = len;
	}
}

//Index ƥ���ַ���
int Index(HString string, HString Sub, int pos)
{
	int n, m, i;
	HString temp;
	ClearString(temp);
	if (pos>=0)
	{
		n = StrLength(string);
		m = StrLength(Sub);
		i = pos;
		while (i <= n - m + 1)
		{
			SubString(temp, string, i, m);
			if (StrCompare(temp, Sub) != 0)
				++i;
			else
				return i;
		}
	}
	return -1;
}


//StrInsert �����ַ���
void StrInsert(HString &string, int pos, HString Sub)
{
	int i;
	if (pos<1 || pos>string.length + 1)
		return;
	if (Sub.length)
	{
		string.ch = (char*)realloc(string.ch, sizeof(char)*(Sub.length + string.length));
		if (!string.ch)
			return;
		for (i = string.length - 1;i >= pos - 1;--i)
			string.ch[i + Sub.length] = string.ch[i];
		for (i = 0;i < Sub.length;i++)
			string.ch[pos + i - 1] = Sub.ch[i];
		string.length = Sub.length + string.length;
	}
}

//StrDelete ɾ���ַ���
void StrDelete(HString &string, int pos, int len)
{
	int i;
	if (pos<0 || pos>string.length - len + 1 || len < 0)
		return;
	for (i = pos -1;i <= string.length - len;i++)
		string.ch[i] = string.ch[i+len];
	string.length -= len;
	string.ch = (char*)realloc(string.ch, sizeof(char)*(string.length));
}

//Replace �滻�ַ���
void Replace(HString &string, HString Sub, HString Rstring)
{
	int i = 0; /* �Ӵ�S�ĵ�һ���ַ�����Ҵ�T */
	do
	{
		i = Index(string, Sub, i); /* ���iΪ����һ��i֮���ҵ����Ӵ�T��λ�� */
		if (i>-1) /* ��S�д��ڴ�T */
		{
			StrDelete(string, i, StrLength(Sub)); /* ɾ���ô�T */
			StrInsert(string, i, Rstring); /* ��ԭ��T��λ�ò��봮V */
			i += StrLength(Rstring); /* �ڲ���Ĵ�V����������Ҵ�T */
		}
	} while (i>-1);
}


//DestroyString �����ַ���
void DestroyString()
{
	//nothing;
}

//Strprint ��ӡ�ַ���
void StrPrint(HString string)
{
	for (int i = 0;i < string.length;i++)
		cout << string.ch[i];
	cout << endl;
}


#endif // !_HSTRING_H_
