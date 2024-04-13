#include <iostream>
using namespace std;

int main(){
    int n;
    long silnia = 1.0;

    cout<<"Podaj liczbe nieujemna: ";
    cin>>n;

    if(n>=0){
        for(int i=1 ; i<=n ; ++i){
            silnia *= i;
        }
        cout<<"Silnia "<<n<<" = "<<silnia;
    }
    else{
        cout<<"Error!";
    }
    return 0;
}
