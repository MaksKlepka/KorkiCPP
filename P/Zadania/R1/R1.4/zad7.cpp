#include <iostream>
using namespace std;

int main(){
    int n, m;
    
    cout<<"Podaj pierwsza liczbe: ";
    cin>>n;
    cout<<"Podaj druga liczbe: ";
    cin>>m;

    if(n<m){
        int x=1;
        for(int i=n;i<=m;i++){
            x*=i;
        }
        cout<<x;
    }
    else{
        cout<<"Error!";
    }
    return 0;
}
