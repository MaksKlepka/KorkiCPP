#include <iostream>
#include <vector>
#include <array>
#include <fstream>
using namespace std;

void wczytaj_dla_2_wektorow(const char* sciezka,vector<int>& kilometer,vector<int>& predkosc){
    fstream plik;
    int km, pr;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        while(plik>>km>>pr){
            kilometer.push_back(km);
            predkosc.push_back(pr);
        }
    }
    else{
        cout<<"Plik sie nie otworzyl i nie zapisuje!";
    }
    plik.close();
}

void wczytaj_dla_1_wektora_z_tablica(const char* sciezka,vector<array<int,2>>& ciezarowki){
    fstream plik;
    int km, pr;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        while(plik>>km>>pr){
            ciezarowki.push_back({km,pr});
        }
    }
    else{
        cout<<"Plik sie nie otworzyl i nie zapisuje!";
    }
    plik.close();
}

int zad_1(vector<int>& predkosc){
    int wynik=1;
    int predkosc_min=predkosc.at(predkosc.size()-1);
    for(int i=predkosc.size()-2;i>0;i--){
        if(predkosc_min>=predkosc.at(i)){
            predkosc_min=predkosc.at(i);
            wynik++;
        }
    }
    return wynik;
}

int zad_2(vector<int>& predkosc){
    int najdlusza_kolumna=1;
    int kolumna=0;
    int predkosc_min=predkosc.at(predkosc.size()-1);
    for(int i=predkosc.size();i>0;i--){
        if(najdlusza_kolumna<=kolumna){
            najdlusza_kolumna=kolumna;
        }
        if(predkosc_min>=predkosc.at(i-1)){
            predkosc_min=predkosc.at(i-1);
            kolumna=0;
        }
        kolumna++;
    }
    return najdlusza_kolumna;
}

int zad_3(vector<int>& predkosc){
    int predkosc_min=predkosc.at(predkosc.size()-1);
    int roznica=0;
    int roznica_wynik=0;
    for(int i=predkosc.size();i>0;i--){
        if(predkosc_min>=predkosc.at(i-1)){
            predkosc_min=predkosc.at(i-1);
        }
        roznica=predkosc.at(i-1)-predkosc_min;
        if(roznica>roznica_wynik){
            roznica_wynik=roznica;
        }
    }
    return roznica_wynik;
}

void reset_file(const char* sciezka){
    fstream plik;
    plik.open(sciezka,ios_base::out|ios_base::trunc);
    plik.close();
}

void zapisz(const char* sciezka, int wynik, int count){
    fstream plik;
    plik.open(sciezka,ios_base::app);
    if(plik.is_open()){
        plik<<"Zadanie 1."<<count<<endl<<endl;
        plik<<wynik<<endl<<endl;
    }
    else{
        cout<<"Plik sie nie otworzyl i nie zapisuje!";
    }
    plik.close();
}

int main(){
    vector <int> kilometer;
    vector <int> predkosc;
    vector <array<int,2>> ciezarowki;
    int count=1;

    const char* sciezka_wczytaj="./dane/BIT18.txt";
    const char* sciezka_zapisz="./odpowiedzi/wyniki1.txt";

    reset_file(sciezka_zapisz);
    wczytaj_dla_2_wektorow(sciezka_wczytaj,kilometer,predkosc);
    zapisz(sciezka_zapisz,zad_1(predkosc),count);
    count++;
    zapisz(sciezka_zapisz,zad_2(predkosc),count);
    count++;
    zapisz(sciezka_zapisz,zad_3(predkosc),count);
    return 0;
}