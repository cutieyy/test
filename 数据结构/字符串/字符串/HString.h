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


//StrAssign 生成一个字符串
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
//StrCopy 复制一个字符串
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

//StrEmpty 判断串是否为空
string StrEmpty(HString String)
{
	if (String.length == 0)
		return "字符串空";
	else
		return "字符串非空";
}

//StrCompare 比较两个字符串
int StrCompare(HString string,HString tstring)
{
	int i;
	for (i = 0;i<string.length&&i<tstring.length;++i)
		if (string.ch[i] != tstring.ch[i])
			return string.ch[i] - tstring.ch[i];
	return string.length - tstring.length;
}

//StrLength 返回字符串长度
int StrLength(HString String)
{
	return String.length;
}

//ClearString 将字符串清空
void ClearString(HString &String)
{
	String.ch = NULL;
	String.length = 0;
}

//ConCat 连接两个字符串
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
//SubString 返回字符串的一个指定的字串
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

//Index 匹配字符串
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


//StrInsert 插入字符串
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

//StrDelete 删除字符串
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

//Replace 替换字符串
void Replace(HString &string, HString Sub, HString Rstring)
{
	int i = 0; /* 从串S的第一个字符起查找串T */
	do
	{
		i = Index(string, Sub, i); /* 结果i为从上一个i之后找到的子串T的位置 */
		if (i>-1) /* 串S中存在串T */
		{
			StrDelete(string, i, StrLength(Sub)); /* 删除该串T */
			StrInsert(string, i, Rstring); /* 在原串T的位置插入串V */
			i += StrLength(Rstring); /* 在插入的串V后面继续查找串T */
		}
	} while (i>-1);
}


//DestroyString 销毁字符串
void DestroyString()
{
	//nothing;
}

//Strprint 打印字符串
void StrPrint(HString string)
{
	for (int i = 0;i < string.length;i++)
		cout << string.ch[i];
	cout << endl;
}


#endif // !_HSTRING_H_
