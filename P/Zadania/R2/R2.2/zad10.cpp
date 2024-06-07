#include <iostream>
using namespace std;

unsigned int NWD(unsigned int p, unsigned int d){
    while(p!=d){
        if(p>d){
            p=p-d;
        }
        else{
            d=d-p;
        }
        }
    return p;
}

unsigned int suma(unsigned int n){
    unsigned int i, sum=0;
    for(i=1;i<n;i++){
        if(NWD(i,n)==1){
            sum+=i;
        }
    }
    return sum;
}

int main(){
    int n;
    cout<<"Prosze podac liczbe n (Program wylicza sume liczb do n, ktore sa wzglednie pierwsze do n): ";
    cin>>n;
    cout<<"Wynik rowna sie: "<<suma(n);
    return 0;
}