#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int w;
    double p;    
    cout<<"Jak chcesz obliczyc pole trojkata?"<<endl;
    cout<<"1 - Z podstawy i wysokosci"<<endl;
    cout<<"2 - Z dlugosci trzech bokow"<<endl;
    cin>>w;
    if(w==1){
        double b,h;
        cout<<"Podaj podstawe trojkata: ";
        cin>>b;
        cout<<"Podaj wysokocs: ";
        cin>>h;
        p=b*h/2;
    }
    else{
        double a,b,c,s;
        cout<<"Podaj pierwszy bok: ";
        cin>>a;
        cout<<"Podaj drugi bok: ";
        cin>>b;
        cout<<"Podaj trzeci bok: ";
        cin>>c;
        s=(a+b+c)/2;
        p=sqrt(s*(s-a)*(s-b)*(s-c));
    }
    cout<<"Pole trojkata wynosi: "<<p<<endl;
    return 0;
}