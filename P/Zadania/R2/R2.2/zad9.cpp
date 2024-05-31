#include <iostream>
using namespace std;

float potengowanie(float i, float m){
    float wynik=i, var=2;
    cout<<"Poczatek pot: i="<<i<<endl;
    do{
        ++var;
        wynik=wynik*i;
    }while(var==m);
    cout<<"koniec pot: wynik="<<wynik<<endl;
    return wynik;
}

float pierwiastkowanie(float n, float m){
    float wynik;
    if(n<=-1){
        n*=-1;
    }
    cout<<"Poczatek pier: "<<endl;
    for(float i=2;potengowanie(i,m)<=n;i++){
        wynik=i;
    }
    cout<<"koniec pier: wynik="<<wynik<<endl;
return wynik;
}

int main(){
    float n, m;
    cout<<"Podaj liczbe n (liczba ktora pierwiastkujesz): ";
    cin>>n;
    cout<<"Podaj liczbe m (liczba ktora pierwiastkujesz przez): ";
    cin>>m;
    cout<<"Twoja liczba to: "<<pierwiastkowanie(n,m)<<endl;
    return 0;
}