#include <iostream>
using namespace std;

int main(){
    unsigned int n;

    cout<<"Podaj liczbe nieujemna: ";
    cin>>n;

    if(n>=0){
        unsigned int suma=0;
        for(unsigned int i=0 ; i<=n ; i++){
            if (i==n)
            {
                cout<<i<<"^2=";
            }
            else
            {
                cout<<i<<"^2+";
            }            
            suma+=i*i;
        }
        cout<<suma<<endl;
    }
    else{
        cout<<"Error!";
    }
    return 0;
}