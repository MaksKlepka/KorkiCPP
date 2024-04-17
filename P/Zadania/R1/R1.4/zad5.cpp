#include <iostream>
using namespace std;

int main(){
    int n;

    cout<<"Podaj liczbe nieujemna: ";
    cin>>n;

    if(n>=0){
        for(float i=0 ; i<=n ; i++){
            cout<<i*i<<endl;
        }
    }
    else{
        cout<<"Error!";
    }
    return 0;
}