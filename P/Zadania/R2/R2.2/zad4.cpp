#include <iostream>
using namespace std;

int n;

int pierwiastkowanie(){
    int m, wynik, kolejna=2;
    while(n>m){
        m++;
        wynik = kolejna * 2;
        kolejna = wynik;    //when I put in 10, it gives me 2^11 not 2^10
        }
    return wynik;
}

int main(){
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<pierwiastkowanie();
}