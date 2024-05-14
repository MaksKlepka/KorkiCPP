#include <iostream>
using namespace std;

int main(){
    int wybor;
    double bok1, bok2, h, wynik;

    cout<<"Dzien dobry, jakie pole figury chcesz policzyc?"<<endl;
    cout<<"1. Kwadrat"<<endl;
    cout<<"2. Prostokat"<<endl;
    cout<<"3. trojkat"<<endl;
    cout<<"Chcialbym wykonac: ";
    cin>>wybor;

    if(wybor==1){
        cout<<"Podaj pierwszy bok: ";
        cin>>bok1;
        wynik=bok1*bok1;
    }
    if(wybor==2){
        cout<<"Podaj pierwszy bok: ";
        cin>>bok1;
        cout<<"Podaj drugi bok: ";
        cin>>bok2;
        wynik=bok1*bok2;
    }
    if(wybor==3){
        cout<<"Podaj pierwszy bok: ";
        cin>>bok1;
        cout<<"Podaj wysokosc: ";
        cin>>h;
        wynik=0.5*bok1*h;
    }
    if(wybor>=4){
        cout<<"Nie wybrales zadnej opcji. Konczenie programu.";
        return 0;
    }
    cout<<"Twoj wynik to: "<<wynik;

return 0;
}