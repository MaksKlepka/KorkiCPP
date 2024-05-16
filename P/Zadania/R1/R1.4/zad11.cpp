#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d, wynik;
    cout<<"Podaj pierwsza liczbe: "; 
    cin>>a;
    cout<<"Podaj druga liczbe: "; 
    cin>>b;
    cout <<"Podaj trzecia liczbe: "; 
    cin>>c;
    cout<<"Podaj czwarta liczbe: "; 
    cin>>d;

    //Przypadek A

    for(int x=0;abs(a)*(x^2)+b*x+c+d>0;x++){
        wynik=x;
    }
    cout<<wynik;

    //Przypadek B

    wynik=0;
    for(int x=0;5*(x^2)+a*x+b+c<0;x++){
        wynik=x;
    }
    cout<<wynik;

    //Przypadek C

    for(int x=0;5*(x^2)+a*x+b+c<=0;x++){
        wynik=x;
    }

    return 0;
}