#include <iostream>
using namespace std;

int main(){
    int liczba;
    cout<<"Podaj liczbe calkowita: ";
    cin>>liczba;

    if (liczba < 0)        
        cout<<"Liczba bezwgledna: "<<-1*liczba<<endl;

    cout<<"Liczba bezwgledna: "<<(liczba<0?-1*liczba:liczba)<<endl;

    return 0;
}