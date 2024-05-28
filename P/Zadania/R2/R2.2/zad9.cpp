#include <iostream>
using namespace std;

int potengowanie(long int i, long int m){
    int  wynik=i;
    for(int i=1;i<=m-1;i++){
        wynik=wynik*i;
    }
    return wynik;
}

long int pierwiastkowanie(long int n, long int m){
    long int wynik;
    if(n<=-1){
        n*=-1;
    }
    for(long int i=2;potengowanie(i,m)<=n;i++){
        wynik=i;
    }
return wynik;
}

int main(){
    long int n, m;
    cout<<"Podaj liczbe n (liczba ktora pierwiastkujesz): ";
    cin>>n;
    cout<<"Podaj liczbe m (liczba ktora pierwiastkujesz przez): ";
    cin>>m;
    cout<<"Twoja liczba to: "<<pierwiastkowanie(n,m)<<endl;
    return 0;
}