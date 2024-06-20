#include <iostream>
using namespace std;

//potengowanie
long int potengowanie(long int m, int i){
    int wynik=i;
    for(int var=2;var<m;var++){
        wynik*=i;
    }
    return wynik;
}

//podłoga z pierwiastka
long int pierwiastkowanie(int j, int m){
    long int wynik;
    for(long int i=0;potengowanie(i, m)<=j;i++){
        wynik=i;
    }
return wynik;
}

//tu sumujemy
int suma(long int n, long int m){
    long int suma=0;
    for(int j=0;j<=n;j++){
        suma+=pierwiastkowanie(j, m);
    }
    return suma;
}

int main(){
    long int n, m;
    cout<<"Prosze podac liczbe n (Program pisze sume Pierwiastkow z liczby m od 0 do n): ";
    cin>>n;
    cout<<"Prosze podac liczbe m: ";
    cin>>m;
    cout<<"Suma rowna sie: "<<suma(n, m);
}