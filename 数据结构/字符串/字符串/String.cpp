//#include"SString.h"
#include"HString.h"
int main()
{
	//SString string,tstring,test,test2,test3;
	HString string, tstring, test, test2, test3;
	StrAssign(string, "zhoujie");
	StrPrint(string);
	cout <<StrLength(string) << endl;
	StrCopy(tstring, string);
	StrPrint(tstring);
	//ClearString(tstring);
	cout << StrLength(tstring) << endl;

	ConCat(string, tstring, test);
	StrPrint(test);
	SubString(test2,string,1, 4);
	StrPrint(test2);
	cout << Index(test,test2, 2) << endl;
	
	cout << "-------------------------------------------------------" << endl;
	StrAssign(test3, "xxx");
	Replace(test, test2, test3);
	StrPrint(test);
/**/
}