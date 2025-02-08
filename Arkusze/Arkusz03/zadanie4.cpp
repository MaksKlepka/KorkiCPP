#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void wczytaj(const char* sciezka, int liczby[]){
    fstream plik;
    plik.open(sciezka, ios_base::in);
    if(plik.is_open()){
        int i = 0;
        while(!plik.eof()){
            plik>>liczby[i];
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

int waga_liczb_do_liczba_jednocyfrowa(int N){
    int wynik=suma_cyfr_wystepujacych_w_liczbie(N);
    while(wynik>=9){
            wynik=suma_cyfr_wystepujacych_w_liczbie(wynik);
    }
    return wynik;
}

string ile_wag_ktore_rownaja_sie_1(int liczby_pierwsze[]){
    string wynik="";
    int ile=0;
    for(int i=0;i<200;i++){
        if(waga_liczb_do_liczba_jednocyfrowa(liczby_pierwsze[i])==1){
            wynik+=liczby_pierwsze[i]+"\n"; //jak int zamienić na strung?
            ++ile;
        }
    }
    return ile+"\n"+wynik; //jak int zamienić na strung?
}

void wyniki4_3(const char* sciezka, int liczby_pierwsze[]){
    fstream plik;
    string wynik = ile_wag_ktore_rownaja_sie_1(liczby_pierwsze);
    plik.open(sciezka,ios_base::out);
    if(plik.is_open()){
        plik<<"Zadanie 4.3"<<endl;
        plik<<"Jest dokladnie "<<wynik<<" liczb ktorych waga rowna sie 1."<<endl<<endl;
    }
    else{
        cout<<"Plik sie nie otworzyl przy zapisywaniu!";
    }
}

int main(){
    int liczby[300];
    int liczby_pierwsze[200];

    const char* sciezka1 = "./dane/liczby.txt";
    const char* sciezka2 = "./dane/pierwsze.txt";

    const char* wyniki = "./odpowiedzi/wyniki4_3.txt";

    wczytaj(sciezka1, liczby);
    wczytaj(sciezka2, liczby_pierwsze);

    wyniki4_3(wyniki,liczby_pierwsze);
}