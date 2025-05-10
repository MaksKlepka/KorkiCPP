#include <iostream>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

void wczytaj(const char* sciezka, int N[], string szyfrogram[]){
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open())
    {
        int i=0;
        while(!plik.eof())
        {
            plik>>N[i];
            plik>>szyfrogram[i];
            ++i;
        }
        plik.close();
    }
    else{
        cout<<"Plik sie nie otworzyl!"<<endl;
    }
    return;
}

void zadanie_3_1(int n, string tekst){
    int k;
    string pomocnicza;
    set <string> wzorce;

    k=tekst.size();
    for(int i=0;i<=k-n;i++){
        pomocnicza="";
        for(int j=0;j<n;j++){
            pomocnicza+=tekst[i+j];
        }
        wzorce.insert(pomocnicza);
    }
    for(string i : wzorce){
        cout<<i<<endl;
    }
}

int czy_zawiera(int N, string szyfrogram){
    int k;
    int count=0;
    string pomocnicza;
    set <string> wzorce;

    k=szyfrogram.size();
    for(int i=0;i<=k-N;i++){
        pomocnicza="";
        for(int j=0;j<N;j++){
            pomocnicza+=szyfrogram[i+j];
        }
        for(int x=1;x<N;x++){
            if(pomocnicza[0]!=pomocnicza[x]){
                count++;
                break;
            }
        }
        pomocnicza.clear();
    }
    return count;
}

string zadanie_3_2(int N[], string szyfrogram[]){
    stringstream wynik;
    cout<<"Zadanie 3.2: "<<endl<<endl;
    for(int i=0;i<10;i++){
        wynik<<czy_zawiera(N[i],szyfrogram[i])<<endl;
    }
    return wynik.str();
}

int main(){
    const char* sciezka_wczytaj = "./dane/szyfrogram.txt";
    const char* sciezka_zapisz = "./odpowiedzi/wyniki3.txt";
    int N[10];
    string szyfrogram[10];

    wczytaj(sciezka_wczytaj,N,szyfrogram);
    cout<<zadanie_3_2(N,szyfrogram);
}