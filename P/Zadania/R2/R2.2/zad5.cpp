#include <iostream>
using namespace std;

//const double Pi=3.14;

double pot2(double n, double m){
    double  wynik=1;
    if(n<0){
        n*=-1;
    }
    for(int i=0;i<n;i++){
        wynik*=2;
    }
    if(m<0){
        wynik=1/wynik;
    }
    return wynik;
}

int main(){
    double n, m;
    cout<<"Podaj liczbe: ";
    cin>>n;
    m=n;
    cout<<"Twoja liczba to: "<<pot2(n, m);
}