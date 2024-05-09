#include <iostream>
using namespace std;

double n, m;

double pierwiastkowanie(){
    double  wynik=n, temp=m;
    if(m<=0){
        m*=-1;
    }

    for(int i=1;i<=m-1;i++){
        wynik=wynik*n;
    }

    if(temp<=0){
        wynik=1/wynik;
    }

    return wynik;
}

int main(){
    cout<<"Podaj liczbe n: ";
    cin>>n;
    cout<<"Podaj liczbe m: ";
    cin>>m;
    cout<<"Twoja liczba to: "<<pierwiastkowanie()<<endl; 
}