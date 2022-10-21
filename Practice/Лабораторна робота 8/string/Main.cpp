#include"String.h"
#include"Markow.h"

int main() 
{
	//work of type String
	char s[] = "aaababab";
	char m[] = "nnnnnnnnnnnn";
	String str(s);
	String str1(m);
	String str2 = str + str1;
	cout << "Concatination of strings:\n\n" << str2<<endl;

	system("pause"); cout << endl;

	//markow for String
	char par1[3] = "bb"; //change to b
	char par2[3] = "ba"; //change to a
	char par3[3] = "ab"; //change to symbol ' ' 
	String rez = markow_in_String(str, par1, par2, par3); //aa
	cout <<"Markow in String: "<< rez<<endl;

	system("pause"); cout << endl;

	//markow for string
	string a = "aaabb";
	char p1[3] = "ba";  //change to a
	char p2[3] = "bb";	//change to b
	char p3[3] = "aa";	//change to symbol ' ' 
	cout<<"Markow in string: "<<algorithm_markowa_in_standard_type(a,p1,p2,p3)<<endl<<endl; //b

	system("pause"); cout << endl;

	return 0;
}