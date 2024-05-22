#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a, b, c, d, wynik;
    cout<<"Podaj pierwsza liczbe: "; 
    cin>>a;
    cout<<"Podaj druga liczbe: "; 
    cin>>b;
    cout <<"Podaj trzecia liczbe: "; 
    cin>>c;
    cout<<"Podaj czwarta liczbe: "; 
    cin>>d;

    //Przypadek A
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

    //Przypadek B, dalej nie zrobiony
    x=0;
    while(false){
        if(5*(x*x)+a*x+b-c<0){
            break;
        }
        ++x;
    }
    wynik=x;
    cout<<"B: "<<wynik<<endl;

    //Przypadek C, dalej nie zrobiony
    x=0;
    while(false){
        if(5*(x*x)+a*x+b-c<=0){
            break;
        }
        ++x;
    }
    wynik=x;
    cout<<"C: "<<wynik<<endl;

    return 0;
}