#include <iostream>
using namespace std;

//const double Pi=3.14;

int pot2(unsigned int n){
    int  wynik=1;
    for(unsigned int i=0;i<n;i++){
        wynik*=2;
    }
    return wynik;
}

int main(){
    unsigned int n;
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<pot2(n);
}