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

    //?

    while(wielokrotnosc>m&&wielokrotnosc<k) {
        cout<<wielokrotnosc<<endl;
        wielokrotnosc+=n;        
    }//Nie jestem pewien czy ten kod dziala poprawnie z zadaniem...

    return 0;
}