#include <iostream>
using namespace std;

int main(){
    int n, m, a, b, dzielnik;
    cout<<"Podaj pierwsza liczbe: ";
    cin>>n;
    a=n;
    cout<<"Podaj druga liczbe: ";
    cin>>m;
    b=m;

    // Euklides wersja z odejmowaniem

    if(n==m){
        cout<<"Najwiekszy wspolny dzielnik: "<<n<<endl;
        return 0; 
    }

    do
    {
        if(n>m) {
            n=n-m;
        }
        else {
            m=m-n;
        }
    }
    while(n!=m);
    cout<<"Najwiekszy wspolny dzielnik: "<<n<<endl;

    //Euklides wersja z reszta z dzielenia
    while (b!=0){
        dzielnik=b;
        b=a%b;
        a=dzielnik;
    }
    cout<<"Najwiekszy wspolny dzielnik: "<<a<<endl;  
    return 0;
}