#include <iostream>
using namespace std;

long int pierwiastkowanie(long int n){
    long int wynik;
    if(n<=-1){
        n*=-1;
    }
    for(long int i=2;i*i<=n;i++){
        wynik=i;
    }
return wynik;
}

int main(){
    long int n;
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<pierwiastkowanie(n)<<endl;
}