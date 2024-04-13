#include <iostream>
using namespace std;

int main()
{
    int liczba1,liczba2,wb1,wb2;
    cout<<"Podaj pierwsza liczbe: ";
    cin>>liczba1;
    wb1=(liczba1<0?-1*liczba1:liczba1);
    cout<<"Podaj druga liczbe: ";
    cin>>liczba2;
    wb2=(liczba2<0?-1*liczba2:liczba2);

    if(wb1>wb2){
        cout<<"Wieksza liczba to: "<<liczba1;
    }
    else{
        cout<<"Wieksza liczba to: "<<liczba2;
    }

    return 0;
}