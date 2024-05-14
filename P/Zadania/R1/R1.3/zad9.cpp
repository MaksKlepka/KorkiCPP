#include <iostream>
using namespace std;

int main(){
    double liczba1, liczba2, wybor;

    cout<<"Dzien dobry, witam w kalkulatorze. Jaka operacje chcialbys wykonac?"<<endl;
    cout<<"1. Dodawanie"<<endl;
    cout<<"2. Odejmowanie"<<endl;
    cout<<"3. Mnozenie"<<endl;
    cout<<"4. Dzielenie"<<endl;
    cout<<"Chcialbym wykonac: ";
    cin>>wybor;

    if(wybor==1){
        cout<<"Podaj pierwsza liczbe: ";
        cin>>liczba1;
        cout<<"Podaj druga liczbe: ";
        cin>>liczba2;

        cout<<"Wynik to: "<<liczba1+liczba2;
    }

    if(wybor==2){
        cout<<"Podaj pierwsza liczbe: ";
        cin>>liczba1;
        cout<<"Podaj druga liczbe: ";
        cin>>liczba2;

        cout<<"Wynik to: "<<liczba1-liczba2;
    }

    if(wybor==3){
        cout<<"Podaj pierwsza liczbe: ";
        cin>>liczba1;
        cout<<"Podaj druga liczbe: ";
        cin>>liczba2;

        cout<<"Wynik to: "<<liczba1*liczba2;
    }

    if(wybor==4){
        cout<<"Podaj pierwsza liczbe: ";
        cin>>liczba1;
        cout<<"Podaj druga liczbe: ";
        cin>>liczba2;

        cout<<"Wynik to: "<<liczba1/liczba2;
    }

    if(wybor>=5){
        cout<<"Nie wybrales zadnej opcji. Konczenie programu.";
    }
return 0;
}