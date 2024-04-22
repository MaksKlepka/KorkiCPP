#include <iostream>
using namespace std;

int n;

int szukaj(){
    int m=n;
    for(int k=2;n<=k;k++){
        m=n/k;
        cout<<k; //find out how to do this, something to do with n/k
    }
    return 0;
}

int main(){
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<szukaj();
}