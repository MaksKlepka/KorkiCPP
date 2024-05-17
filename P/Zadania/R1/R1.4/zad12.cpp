#include <iostream>
using namespace std;

unsigned int NWD(unsigned int p,unsigned int d){
    while(p!=d)
        if(p>d){
            p=p-d;
        }
        else
            d=d-p;
    return p;
}

unsigned int suma(unsigned int n){
    int i, sum=0;
    for(i=1;i<n;i++){
        if(NWD(i,n)==1){
            sum+=i;
        }
    }
    return sum;
}

int main(){
    int n;
    cout<<"Podaj liczbe calkowita: ";
    cin>>n;
    cout<<"Wynik obliczen to: "<<suma(n);
}