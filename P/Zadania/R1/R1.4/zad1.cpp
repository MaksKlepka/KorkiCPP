#include <iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Podaj pierwsza liczbe dodatnia: ";
    cin>>n;
    cout<<"Podaj druga liczbe dodania: ";
    cin>>m;
    for(int i=n;i<m;i+=n){
        cout<<i<<endl;
    }
    return 0;
}