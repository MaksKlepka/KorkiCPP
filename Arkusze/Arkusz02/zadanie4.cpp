#include <iostream>
#include <fstream>
#include <sstream>

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

string najdluszy_fragment_regularnej(int liczby[]){
    stringstream wynik;
    int count=2, count_max=0, pierwsza_liczba, ostatnia_liczba;
    for(int i=0;i<=998;i++){
        if(luka_pomiedzy_dwoma_liczbami(liczby,i)==luka_pomiedzy_dwoma_liczbami(liczby,i+1)){
            count+=1;
            if(count>count_max){
                count_max=count;
                pierwsza_liczba=liczby[i];
                ostatnia_liczba=liczby[i+count_max-1];
            }
        }
        else{
            count=2;
        }
    }
    wynik<<"Najwieksza dlugosc fragmentu regularnego: "<<count_max<<endl;
    wynik<<"Poczatek: "<<pierwsza_liczba<<endl;
    wynik<<"Koniec: "<<ostatnia_liczba<<endl<<endl;
    return wynik.str();
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
        plik<<"Najwieksza luka: "<<najwieksza_luka(liczby)<<endl;
        plik<<"Najmniejsza luka: "<<najmniejsza_luka(liczby)<<endl<<endl;
    }
    else{
        cout<<"Plik sie nie otworzyl!"<<endl;
    }
    return;
}

void zapisz2(const char* sciezka, int liczby[]){
    fstream plik;
    plik.open(sciezka,ios_base::app);
    if(plik.is_open()){
        plik<<"Zadanie 4.2"<<endl;
        plik<<najdluszy_fragment_regularnej(liczby);
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

    wczytaj(sciezka1, liczby);
    zapisz1(sciezka2, liczby);
    zapisz2(sciezka2, liczby);
    najdluszy_fragment_regularnej(liczby);
}