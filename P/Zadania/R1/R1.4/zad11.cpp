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

    /*for(int x=0;abs(a)*(x*x)+b*x+c-d<=0;x++){
        wynik=x;
    }*/

    int x=0;
    while (true)
    {
        if (abs(a)*(x*x)+b*x+c-d>0)
        {
            break;
        }
        ++x;
    }
    wynik=x;
    cout<<"A: "<<wynik<<endl;

    //Przypadek B

    wynik=0;
    for(int x=0;5*(x*x)+a*x+b+c<0;x++){
        wynik=x;
    }
    cout<<"B: "<<wynik<<endl;

    //Przypadek C

    for(int x=0;5*(x*x)+a*x+b+c<=0;x++){
        wynik=x;
    }
    cout<<"C: "<<wynik<<endl;

    return 0;
}