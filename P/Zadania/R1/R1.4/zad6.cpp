#include <iostream>
using namespace std;

int main(){
    int n;

    cout<<"Podaj liczbe calkowita (Wieksza od 2): ";
    cin>>n;

    if(n>2){
        int iloczyn=1;
        for(int i=2;i<=n;i+=2){
           iloczyn*=i;
        }
        cout<<"Iloczyn: "<<iloczyn<<endl;
    }
    else{
        cout<<"Error!";
    }
    return 0;
}