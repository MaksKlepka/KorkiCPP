#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void wczytaj1(const char* sciezka, int liczby_naturalne[]){
    fstream plik;
    plik.open(sciezka, ios_base::in);
    if(plik.is_open()){
        int i = 0;
        while(!plik.eof()){
            plik>>liczby_naturalne[i];
            i++;
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie wczytal!";
    }
    return;
}

void wczytaj2(const char* sciezka, int liczby_pierwsze[]){
    fstream plik;
    plik.open(sciezka, ios_base::in);
    if(plik.is_open()){
        int i = 0;
        while(!plik.eof()){
            plik>>liczby_pierwsze[i];
            i++;
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie wczytal!";
    }
    return;
}

int suma_cyfr_wystepujacych_w_liczbie(int N){
    int wynik=0;
    while(N!=0){
        wynik = wynik + (N%10);
        N=N/10;
    }
    return wynik;
}

string temp(int N[]){
    int temp=suma_cyfr_wystepujacych_w_liczbie(N[0]);
    stringstream wynik;
    for(int i=0;temp/10==0;i++){
        
    }

}


int main(){
    int liczby_naturalne[300];
    int liczby_pierwsze[200];

    const char* sciezka1 = "./dane/liczby.txt";
    const char* sciezka2 = "./dane/pierwsze.txt";

    wczytaj1(sciezka1, liczby_naturalne);
    wczytaj2(sciezka2, liczby_pierwsze);

    cout<<suma_cyfr_wystepujacych_w_liczbie(liczby_pierwsze[0]);
}