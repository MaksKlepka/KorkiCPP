#include <iostream>
using namespace std;

//iteracyjnie
unsigned int silniaI(unsigned int liczba)
{
    if (liczba==0||liczba==1) return 1;
    unsigned int wynik=1;
    for (unsigned int i=2;i<=liczba;++i)
    {
        wynik*=i;
    }
    return wynik;
}

unsigned int silniaR(unsigned int liczba)
{
    if (liczba==0||liczba==1) return 1;
    return liczba*silniaR(liczba-1);
}

int main(){
    unsigned int liczba;
    cout<<"Podaj liczbe: ";
    cin>>liczba;

    cout<<"Silnia iteracyjnie: "<<silniaI(liczba)<<endl;
    cout<<"Silnia iteracyjnie: "<<silniaR(liczba)<<endl;


    return 0;
}