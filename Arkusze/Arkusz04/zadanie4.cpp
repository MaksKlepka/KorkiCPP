#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void wczytaj(const char* sciezka,int liczby1[],int liczby2[],int ile){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        int i = 0;        
        while(i<ile){
            plik>>liczby1[i];
            ++i;
        }
        i=0;
        while(i<20){
            plik>>liczby2[i];           
            ++i;
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie wczytal!";
    }
    return;
}

void wczytaj1(const char* sciezka,int liczby1[],int liczby2[]){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        for(unsigned int i=0;i<3000;++i){
            plik>>liczby1[i];
        }
        for (unsigned int i=0;i<20;++i){
            plik>>liczby2[i];
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie wczytal!";
    }
    return;
}

int ile_dzielnikow(int liczby1[], int liczby2[],int ile){
    int wynik=0;
    for(int j=0 ;j<ile ;++j){
        for(int i=0 ; i<20 ; ++i){
            if(liczby2[i] % liczby1[j] == 0){
                ++wynik;
                break;
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
    //int liczby1p[200];
    int liczby2[20];

    const char* sciezka_wczytaj = "./Dane/liczby.txt";
    //const char* sciezka_wczytajp = "./Dane/liczby_przyklad.txt";
    const char* sciezka_zapisz = "./Odpowiedzi/wyniki4.txt";
    
    wczytaj(sciezka_wczytaj,liczby1,liczby2,3000);
    zapisz1(sciezka_zapisz,ile_dzielnikow(liczby1,liczby2,3000));

}