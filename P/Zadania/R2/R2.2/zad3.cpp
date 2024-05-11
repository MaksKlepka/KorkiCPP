#include <iostream>
using namespace std;

int szukaj(int n){

    int k=n-1;
    while (n%k!=0){
        --k;
    }    
    return k;
}

int main(){
    int n;
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<szukaj(n);
}