//niedoknonczone bo nie rozumiem za bardzo struktury

#include <iostream>
using namespace std;

int main(){
    /*
    int liczba1, liczba2, liczba3;
    cout<<"Podaj pierwsza liczbe calkowita: ";cin>>liczba1;
    cout<<"Podaj druga liczbe calkowita: ";cin>>liczba2;
    cout<<"Podaj trzecia liczbe calkowita: ";cin>>liczba3;

    if(liczba1>liczba2){
        if(liczba1>liczba3){
            cout<<"Najwieksza liczba to: "<<liczba1<<endl;}
        else if(liczba3>liczba1){
            cout<<"Najwieksza liczba to: "<<liczba3<<endl;}
        else{
            cout<<"Najwieksze liczby to: "<<liczba1<<" i "<<liczba3<<endl;}
    }

    else if(liczba2>liczba3){
        if(liczba2>liczba3){
            cout<<"Najwieksza liczba to: "<<liczba2<<endl;}
        else if(liczba3==liczba2){
            cout<<"Najwieksze liczby to: "<<liczba2<<" i "<<liczba3<<endl;}
        else {
            cout<<"Najwieksza liczba to: "<<liczba3<<endl;
            }
    }

    else{
        if(liczba3>liczba1){
            cout<<"Najwieksza liczba to: "<<liczba3<<endl;}
        else if(liczba1>liczba3){
            cout<<"Najwieksze liczby to: "<<liczba1<<" i "<<liczba2<<endl;}
        else{
            cout<<"Liczby sa takie same"<<endl;}
    }
    */

    int wieksza,kolejna;

    cout<<"Podaj pierwsza liczbe: ";
    cin>>wieksza;

    cout<<"Podaj druga liczbe: ";
    cin>>kolejna;
    if (kolejna>wieksza)
        wieksza=kolejna;
    //wieksza=(kolejna>wieksza?kolejna:wieksza);

    cout<<"Podaj trzecia liczbe: ";
    cin>>kolejna;
        if (kolejna>wieksza)
    wieksza=kolejna;

    cout<<"najwieksza to: "<<wieksza<<endl;

   return 0;
}