#include <iostream>
#include <fstream>

using namespace std;

void wczytaj(const char* sciezka, int liczby[]){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open())
    {
        int i=0;
        while(!plik.eof())
        {
            plik>>liczby[i];
            ++i;
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie otworzyl!"<<endl;
    }
    return;
}

int luka_pomiedzy_dwoma_liczbami(int liczby[], int i){
    int wynik = liczby[i]-liczby[i+1];
    if(wynik<0){
        wynik=wynik*(-1);
    }
    return wynik;
}

int najwieksza_luka(int liczby[]){
    int i=0, wynik=luka_pomiedzy_dwoma_liczbami(liczby,i);

    while(i<998){
        if(wynik<luka_pomiedzy_dwoma_liczbami(liczby,i+1)){
            wynik=luka_pomiedzy_dwoma_liczbami(liczby,i+1);
            ++i;
        }
        else{
            ++i;
        }
    }
    return wynik;
}

int najmniejsza_luka(int liczby[]){
    int i=0, wynik=luka_pomiedzy_dwoma_liczbami(liczby,i);

    while(i<998){
        if(wynik>luka_pomiedzy_dwoma_liczbami(liczby,i+1)){
            wynik=luka_pomiedzy_dwoma_liczbami(liczby,i+1);
            ++i;
        }
        else{
            ++i;
        }
        
    }
    return wynik;
}

void zapisz1(const char* sciezka, int liczby[]){
    fstream plik;
    plik.open(sciezka,ios_base::out);
    if(plik.is_open()){
        plik<<"Zadanie 4.1"<<endl;
        plik<<najwieksza_luka(liczby)<<endl;
        plik<<najmniejsza_luka(liczby)<<endl<<endl;
    }
    else{
        cout<<"Plik sie nie otworzyl!"<<endl;
    }
    return;
}

int main(){
    int liczby[999];

    const char* sciezka1 = "./dane/dane4.txt";
    const char* sciezka2 = "./odpowiedzi/zadanie4.txt";

    wczytaj(sciezka1,liczby);
    cout<<"Zadanie 4.1"<<endl;
    cout<<"Najwieksza luka: "<<najwieksza_luka(liczby)<<endl;
    cout<<"Najmniejsza luka: "<<najmniejsza_luka(liczby)<<endl;
    zapisz1(sciezka2, liczby);
}