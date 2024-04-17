#include <iostream>
using namespace std;

int main(){
    int n;

    cout<<"Podaj liczbe calkowita (Wieksza od 2): ";
    cin>>n;

    if(n>2){
        int m;
        for(int i=2;i<=n;i*=2){
            //Nie za pewny jak ta pentle skonfigurowac
        }
        cout<<m;
    }
    else{
        cout<<"Error!";
    }
    return 0;
}