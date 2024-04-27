#include <iostream>
using namespace std;

int main(){
    unsigned int n, m, k;
    cout<<"Podaj pierwsza liczbe dodatnia : "; //multiplication
    cin>>n;
    cout<<"Podaj druga liczbe dodatnia: "; //low/high
    cin>>m;
    cout<<"Podaj trzecia liczbe dodatnia: "; //low/high
    cin>>k;
    
    unsigned int wielokrotnosc=n;    
    
    //sposob 1
    while (wielokrotnosc<=m)
    {
        wielokrotnosc+=n;
    }

    while(wielokrotnosc>m&&wielokrotnosc<k) {
        cout<<wielokrotnosc<<endl;
        wielokrotnosc+=n;        
    }

    //sposob 2
    while(wielokrotnosc<k) {
        if (wielokrotnosc>m)
        {
            cout<<wielokrotnosc<<endl;
        }        
        wielokrotnosc+=n;
    }

    return 0;
}