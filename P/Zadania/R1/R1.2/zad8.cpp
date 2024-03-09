#include <iostream>
using namespace std;

int main()
{
int liczba1, liczba2, liczba3;
cout<<"Podaj 3 liczby calkowite"<<endl; 
cout<<"Pierwsza liczba = "; cin>>liczba1;
cout<<"Druga liczba = "; cin>>liczba2;
cout<<"Trzecia liczba = "; cin>>liczba3;
cout<<"Srednia arymetryczna to: "<<(double)(liczba1+liczba2+liczba3)/3<<endl;
//uwaga
//int x;
//double y;
//y=(double)x; - OK
//x=(int)y; - ZLE!!!

//typy w operatorach arytmetycznych
cout<<"suma = "<<liczba1+liczba2+1.0*liczba3<<endl;
return 0;

}