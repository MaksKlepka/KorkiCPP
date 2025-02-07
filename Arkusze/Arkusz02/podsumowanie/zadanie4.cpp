#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void wczytaj(const char* sciezka, int liczby[]){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        int i=0;
        while(!plik.eof()){
            plik>>liczby[i];
            ++i;
        }
    }
    else{
        cout<<"Plik nie otworzyl sie!"<<endl;
    }
    return;
}

void luka_pomiedzy_liczbami_import(int liczby[],int luka[]){
    int i=0;
    int temp=0;
    while(i<=999){
        if(liczby[i]-liczby[i+1]<0){
            temp=(liczby[i]-liczby[i+1])*-1;
        }
        else{
            temp=(liczby[i]-liczby[i+1]);
        }
        luka[i]=temp;
        i++;
    }
    return;
}

string najdluszy_fragment_regularnej(){

}

int main(){
    const char* sciezka= "dane/dane4.txt";
    int liczby[1000];
    int luka[999];

    wczytaj(sciezka,liczby);
    luka_pomiedzy_liczbami_import(liczby,luka);
    cout<<luka[0]<<endl;
    cout<<luka[1];
}