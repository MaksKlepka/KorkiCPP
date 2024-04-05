#include <iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Podaj pierwsza liczbe dodatnia: ";
    cin>>n;
    cout<<"Podaj druga liczbe dodatnia: ";
    cin>>m;
    for(int i=0;i<m;i++){
        int mnoznik=i+2;
        cout<<n*mnoznik<<endl;
    }
    return 0;
}