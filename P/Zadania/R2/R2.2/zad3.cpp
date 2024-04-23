#include <iostream>
using namespace std;

int n;

int szukaj(){
    int m=0;
    for(int k=2;k<=n;k++){
        m=n/k;
        cout<<m; //find out how to do this, something to do with n/k
    }
    return 0;
}

int main(){
    cout<<"Podaj liczbe: ";
    cin>>n;
    cout<<"Twoja liczba to: "<<szukaj();
}