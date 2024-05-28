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
    cout<<"A: "<<x<<endl;

    //Przypadek B
    
    float wartosc_w0 = b-c;
    x = 1;
    while(true){
        float wartosc_wx = 5*(x*x)+a*x+b-c;        
        if (wartosc_w0>=0)
        {
            //czy warto szukac
            if (wartosc_wx>wartosc_w0)
            {
                cout<<"Brak takiej liczby!"<<endl;
                break;
            }
            ++x;
        }
        else
        {
            //szukamy
            ++x;
            if (5*(x*x)+a*x+b-c>=0)
            {
                break;
            }
        }       
    }
    cout<<"B: "<<x-1<<endl;

    //Przypadek C, dalej nie zrobiony

    x=1;
    while(true){
        float wartosc_wx = 5*(x*x)+a*x+b-c;        
        if (wartosc_w0>0)
        {
            //czy warto szukac
            if (wartosc_wx>wartosc_w0)
            {
                cout<<"Brak takiej liczby!"<<endl;
                break;
            }
            ++x;
        }
        else
        {
            //szukamy
            ++x;
            if (5*(x*x)+a*x+b-c>0)
            {
                break;
            }
        }       
    }
    cout<<"C: "<<x-1<<endl;

    return 0;
}