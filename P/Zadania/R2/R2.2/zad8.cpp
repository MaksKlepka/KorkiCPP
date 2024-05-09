#include <iostream>
using namespace std;

long int n;

long int pierwiastkowanie(){
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
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<pierwiastkowanie()<<endl;
}