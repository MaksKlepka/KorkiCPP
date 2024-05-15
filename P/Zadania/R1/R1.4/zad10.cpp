#include <iostream>
using namespace std;

int main()
{
    long int n, wynik;

    cout<<"Jaka liczbe chcesz zpierwiastkowac? : ";
    cin>>n;

    if(n<=-1){
        n*=-1;
    }

    for(long int i=2;i*i<=n;i++){
        wynik=i;
    }

    cout<<"Twoj wynik jest: "<<wynik;
    
    return 0;
}