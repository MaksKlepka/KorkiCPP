#include <iostream>
using namespace std;

void zamiennik(int & wskaznik1, int & wskaznik2){
    int temp;
    if(wskaznik1>wskaznik2){
        temp=wskaznik1;
        wskaznik1=wskaznik2;
        wskaznik2=temp;
    }
}

int main(){
    int* wskaznik1;
    int* wskaznik2;

    cout<<"Podaj wartosci a i b:"<<endl;
    cout<<"a = ";
    cin>>*wskaznik1;
    cout<<"b = ";
    cin>>*wskaznik2;
    zamiennik(wskaznik1, wskaznik2);
}