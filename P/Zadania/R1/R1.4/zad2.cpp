#include <iostream>
using namespace std;

int main(){
    unsigned int n,m;
    cout<<"Podaj pierwsza liczbe dodatnia: ";
    cin>>n;
    cout<<"Podaj druga liczbe dodatnia: ";
    cin>>m;

    for(unsigned int i=0;i<m;i++){        
        cout<<n*(i+1)<<endl;
    }

    return 0;
}