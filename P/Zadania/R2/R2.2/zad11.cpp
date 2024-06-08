#include <iostream>
using namespace std;

//podłoga z pierwiastka
long int pierwiastkowanie(int j){
    long int wynik;
    for(long int i=0;i*i<=j;i++){
        wynik=i;
    }
return wynik;
}

//tu sumujemy
int suma(long int n){
    long int suma=0;
    for(int j=0;j<=n;j++){
        suma+=pierwiastkowanie(j);
    }
    return suma;
}

int main(){
    long int n;
    cout<<"Prosze podac liczbe n (Program pisze sume Pierwiastkow od 0 do n): ";
    cin>>n;
    cout<<"Suma rowna sie: "<<suma(n);
}