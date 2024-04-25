#include <iostream>
using namespace std;

int n;

int pierwiastkowanie(){
    int  wynik=2;
    for(int i=1;i<=n-1;i++){
        wynik=wynik*2;
    }
    return wynik;
}

int main(){
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<pierwiastkowanie();
}