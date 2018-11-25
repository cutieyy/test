#pragma once
#ifndef _SSTRING_H_
#include<iostream>
using namespace std;
#define MAXSTRING 255
typedef unsigned char SString[MAXSTRING+1];

//StrAssign 生成一个字符串
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

//StrCopy 复制一个字符串
void StrCopy(SString String,SString TString)
{
	int i;
	for (i = 0;i <=TString[0];i++)
		String[i] = TString[i];
}

//StrEmpty 判断串是否为空
string StrEmpty(SString String) 
{
	if (String[0] == 0)
		return "字符串空";
	else
		return "字符串非空";
}

//StrCompare 比较两个字符串
int StrCompare(SString string, SString tstring)
{
	int i;
	for (i = 1;i <= (int)string[0] && (int)tstring[0];++i)
		if (string[i] != tstring[i])
			return (int)(string[i] - tstring[i]);
	return string[0] - tstring[0];
}

//StrLength 返回字符串长度
int StrLength(SString String)
{
	return (int)String[0];
}

//ClearString 将字符串清空
void ClearString(SString String)
{
	String[0] = 0;
}

//ConCat 连接两个字符串
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

//SubString 返回字符串的一个指定的字串
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

//Index 匹配字符串
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

//StrInsert 插入字符串
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

//StrDelete 删除字符串
void StrDelete(SString string, int pos, int len)
{ 
	int i;
	if (pos<1 || pos>string[0] - len + 1 || len < 0)
		return;
	for (i = pos + len;i <= string[0];i++)
		string[i - len] = string[i];
	string[0] -= len;
}

//Replace 替换字符串
void Replace(SString string, SString Sub, SString Rstring)
{
	int i = 1; /* 从串S的第一个字符起查找串T */
	do
	{
		i = Index(string, Sub, i); /* 结果i为从上一个i之后找到的子串T的位置 */
		if (i) /* 串S中存在串T */
		{
			StrDelete(string, i, StrLength(Sub)); /* 删除该串T */
			StrInsert(string, i, Rstring); /* 在原串T的位置插入串V */
			i += StrLength(Rstring); /* 在插入的串V后面继续查找串T */
		}
	} while (i);
}

//DestroyString 销毁字符串
void DestroyString()
{

}

//Strprint 打印字符串
void StrPrint(SString String)
{
	int i;
	for (i = 1;i <= String[0];i++)
		cout << String[i];
	cout << endl;
}

#endif // !_SSTRING_H_
