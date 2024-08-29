#include <iostream>
using namespace std;

void zamien(int *a, int *b){
    int pom;
    pom=*a;
    *a=*b;
    *b=pom;
}

int main(){
    int* a;
    int* b;
    cout<<"Podaj liczbe a";
    cin>>*a;
    cout<<"Podaj liczbe b";
    cin>>*b;
    zamien(a,b);
}