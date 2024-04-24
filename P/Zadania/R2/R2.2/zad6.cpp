#include <iostream>
using namespace std;

int n, m;

int pierwiastkowanie(){
    int  wynik=n;
    for(int i=1;i<=m-1;i++){
        wynik=wynik*n;
    }
    return wynik;
}

int main(){
    cout<<"Podaj liczbe n: ";
    cin>>n;
    cout<<"Podaj liczbe m: ";
    cin>>m;
    cout<<"Twoja liczba to: "<<pierwiastkowanie();
}