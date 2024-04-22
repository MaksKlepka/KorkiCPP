#include <iostream>
using namespace std;

//wczytywanie zmiennej
int wczytaj()
{
    cout<<"Podaj liczbe: ";
    int liczba;
    cin>>liczba;
    return liczba;
}

//liczenie wb
unsigned int wbez(int liczba)
{
    return liczba<0?-liczba:liczba;
}

//wypisywanie
void wypisz(unsigned int liczba)
{
    cout<<"Wartosc bezwzgledna: "<<liczba<<endl;
}



int main(){    
    wypisz(wbez(wczytaj()));    
    return 0;
}