#include <iostream>
using namespace std;

int n, m;

                         // Uwaga PiotrK-73 ta funkcja jest potęgowaniem
int pierwiastkowanie(){
    int  wynik=n;
    for(int i=1;i<=m-1;i++){
        wynik=wynik*n;
    }
    return wynik;
}

int main(){
    cout<<"Podaj liczbe n: ";
                         // Uwaga PiotrK-73 tutaj dodałbym "Podaj liczbe n - podstwe potegi:"
    cin>>n;
    cout<<"Podaj liczbe m: ";
                         // Uwaga PiotrK-73 tutaj dodałbym "Podaj liczbe m - wykladnik potegi:"
    cin>>m;
    cout<<"Twoja liczba to: "<<pierwiastkowanie();
                         // Uwaga PiotrK-73 tutaj dodałbym "Twoja liczba n^m to:"
                         //      ponieważ nie ma zapisanej podstawy n - to nie możemy na przyklad dodać 2^3                    
}
