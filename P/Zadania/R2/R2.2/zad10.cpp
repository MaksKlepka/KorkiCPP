#include <iostream>
using namespace std;

//znajdowanie NWD - Euklides
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

//czy l jest wzg pierwsze z n
bool czyWP(unsigned int l,unsigned int n)
{
    if (NWD(l,n)==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//tu sumujemy
unsigned int suma(unsigned int n){
    unsigned int sum=0;
    for(unsigned int i=1;i<n;i++){
        if(czyWP(i,n)){
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