#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    cout<<"Podaj pierwsza liczbe dodatnia : "; //multiplication
    cin>>n;
    cout<<"Podaj druga liczbe dodatnia: "; //low/high
    cin>>m;
    cout<<"Podaj trzecia liczbe dodatnia: "; //low/high
    cin>>k;
    int i = 1;
    int x = 0;
    while(x < k) {
    x = i * n;
    if(x > m && x < k) cout << x << endl;
    i++;
}//Nie jestem pewien czy ten kod dziala poprawnie z zadaniem...
    return 0;
}