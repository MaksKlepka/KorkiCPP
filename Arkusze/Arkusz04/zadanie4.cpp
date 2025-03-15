#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void wczytaj(const char* sciezka,int liczby1[],int liczby2[]){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        int i = 0;
        int q = 0;
        while(i!=3000){
            plik>>liczby1[i];
            ++i;
        }
        while(i!=3020){
            plik>>liczby2[q];
            ++i;
            ++q;
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie wczytal!";
    }
    return;
}

int ile_dzielnikow(int liczby1[], int liczby2[]){
    int wynik;
    for(int i=0 ; i<19 ; ++i){
        for(int j=0 ; j<2999 ; ++j){
            if(liczby2[j] % liczby1[i] == 0){
                ++wynik;
            }
        }
    }
    return wynik;
}

void zapisz1(const char* sciezka, int wynik){
    fstream plik;
    plik.open(sciezka,ios_base::out);
    if(plik.is_open()){
        plik<<"Zadanie 4.1"<<endl<<endl;
        plik<<"Ilosc dzielnikow: ";
        plik<<wynik<<endl;
    }
    else{
        cout<<"Plik wpisujacy sie nie otworzyl!";
    }
    plik.close();
}
int main(){
    int liczby1[3000];
    int liczby2[20];

    const char* sciezka_wczytaj = "./Dane/liczby.txt";
    const char* sciezka_zapisz = "./Odpowiedzi/wyniki4.txt";
    wczytaj(sciezka_wczytaj,liczby1,liczby2);
    zapisz1(sciezka_zapisz,ile_dzielnikow(liczby1,liczby2));

}