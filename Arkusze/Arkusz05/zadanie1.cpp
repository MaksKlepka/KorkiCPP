#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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

void wczytaj_dla_1_wektora_z_tablica(const char* sciezka,vector<int>& ciezarowki){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        while(!plik.eof()){

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
    for(int i=predkosc.size()-1;i>0;i--){
        if(predkosc_min>=predkosc.at(i-1)){
            predkosc_min=predkosc.at(i-1);
            wynik++;
        }
    }
    return wynik;
}

void zapisz(const char* sciezka, int wynik, int count){
    fstream plik;
    plik.open(sciezka,ios_base::out);
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
    vector <int[2]> ciezarowki;
    int count=1;

    const char* sciezka_wczytaj="./dane/BIT18.txt";
    const char* sciezka_zapisz="./odpowiedzi/wyniki1.txt";

    wczytaj_dla_2_wektorow(sciezka_wczytaj,kilometer,predkosc);
    zapisz(sciezka_zapisz,zad_1(predkosc),count);
    count++;
}