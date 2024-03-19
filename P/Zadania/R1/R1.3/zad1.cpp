#include <iostream>
using namespace std;

int main(){
    int liczba;
    cout<<"Podaj liczbe calkowita: ";cin>>liczba;
        if(liczba < 0)
            liczba *= -1;
    cout<<"Liczba bezwgledna: "<<liczba;
    return 0;
}