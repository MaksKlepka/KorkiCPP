#include <iostream>
using namespace std;

int main(){
    unsigned int n, fib1=1, fib2=1, pom;
    
    cout<<"Podaj liczbe nieujemna i calkowita: ";
    cin>>n;
    for(unsigned int i=2;i<=n;i++){
        pom=fib2;
        fib2=fib1+fib2;
        fib1=pom;        
    }
    cout<<"element ciagu Fibonacciego o indeksie n: "<<fib1;
    return 0;
}