#include <iostream>
using namespace std;

int main(){
    int n;
    long wynik=1.0;

    cout<<"Podaj liczbe: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        wynik*=i;
    }
    cout<<"Silnia "<<n<<" jest rowna: "<<wynik;

    return 0;
}