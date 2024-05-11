#include <iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Podaj pierwsza liczbe: ";
    cin>>n;
    cout<<"Podaj druga liczbe: ";
    cin>>m;
    // Euklides wersja z odejmowaniem
    do
    {
        if(n > m) {
            n=n-m;
        } else {
            m=m-n;
        }
    }
    while(n!=m);
    cout<<"Najwiekszy wspolny dzielnik: "<<n<<endl;

    //Euklides wersja z reszta z dzielenia


    return 0;
}