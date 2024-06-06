#include <iostream>
using namespace std;

int suma(int n){
    int i=0, suma=1;
    while(i<n){
        i++;
        if(n%i == 0){
            cout<<i;
            if (n/i == i){
                suma=suma+i;
            }
        }
    }
    cout<<"Suma jest rowna: "<<suma;
    return 0;
}

int main(){
    cout<<"Prosze podac liczbe n (Program wylicza sume liczb do n, ktore sa wzglednie pierwsze do n): ";
    int n;
    cin>>n;
    suma(n);
    return 0;
}