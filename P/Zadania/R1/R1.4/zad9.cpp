#include <iostream>
using namespace std;

int main(){
    int n, m;
    cout<<"Podaj pierwsza liczbe: ";
    cin>>n;
    cout<<"Podaj druga liczbe: ";
    cin>>m;
    do
    {
        if(n > m) {
            n=n-m;
        } else {
            m=m-n;
        }
    }
    while(n!=m);

    cout<<"Najwiekszy wspolny dzielnik: "<<n<<endl;
    return 0;
}