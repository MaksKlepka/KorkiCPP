#include <iostream>
using namespace std;

int main()
{
    unsigned int n, m;
    cout <<"Podaj liczbe wymierna: "; 
    cin>>n;

    for(unsigned int i = 0 ; n >= m; m = i*i){
        i++; //This one (if n=64) goes to 9*9, not 8*8. Idk why tho
    }
    cout <<"Wartosc bezwzgledna twojej liczby to: "<<m<<endl;
    return 0;
}