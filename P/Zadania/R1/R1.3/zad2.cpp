#include <iostream>
using namespace std;

int main(){
    int liczba1, liczba2;
    cout<<"Podaj pierwsza liczbe calkowita: ";
    cin>>liczba1;
    cout<<"Podaj druga liczbe calkowita: ";
    cin>>liczba2;

    if (liczba1>liczba2)
        cout<<"Wieksza liczba to: "<<liczba1<<endl;
    else
        cout<<"Wieksza liczba to: "<<liczba2<<endl;

    cout<<"Wieksza liczba to: "<<(liczba1>liczba2?liczba1:liczba2)<<endl;

    //wiele liczb
    cout<<"POdawaj liczby, gdy chcesz skonczyc wpisz 0"<<endl;
    int najwieksza,podana;

    cout<<"podaj liczbe:";
    cin>>podana;
    najwieksza=podana;
    if (podana==0)
    {
        cout<<"Najwieksza: "<<podana<<endl;
        return 0;
    }

    while (podana!=0)
    {
        cout<<"podaj liczbe:";
        cin>>podana;
        if (podana>najwieksza) najwieksza=podana;
    }
    cout<<"Najwieksza: "<<najwieksza<<endl;

    
    return 0;
}