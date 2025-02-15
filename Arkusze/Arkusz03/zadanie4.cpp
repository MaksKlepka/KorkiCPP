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


bool czy_w_przedziale(int liczba){
    if(liczba>=100&&liczba<=5000){
        return true;
    }
    return false;
}

bool czy_jest_pierwsza(int liczba){
    if(liczba==0||liczba==1){
        return false;
    }
    //liczba 23 -> 23/2=11,23/3=7,23/4=5,23/6=3,23/7=3,23/8=2,23/9=2,23/10/2,23/11=2
    //jeśli nie jest pierwsza -> liczba=n*m, n<=m -> liczba=n*n
    for(int i=2;i*i<=liczba;++i){
        if(liczba%i==0){
            return false;
        }
    }
    return true;
}

string polaczenie_przedzialu_i_pierwszej(int liczby[]){
    string wynik = "";
    for(int i=0;i<300;++i){
        if(czy_jest_pierwsza(liczby[i]) && czy_w_przedziale(liczby[i])){
            wynik+=to_string(liczby[i])+"\n";
        }
    }
    return wynik;
}

int obrocenie_liczby(int liczba){
    int wynik=0, wspomagajaca;
    while(liczba!=0){
        wspomagajaca=liczba%10;
        wynik=wynik*10+wspomagajaca;
        liczba/=10;
    }
    return wynik;
}

int obracanie_s(int liczba)
{
    string liczbaS = to_string(liczba);
    string liczbaO = "";    
    for (int i=liczbaS.length()-1;i>=0;--i)
    {
       liczbaO+=liczbaS.at(i);
    }
    return stoi(liczbaS);
}

string polaczenie_obrotu_i_pierwszej(int liczby[]){
    string wynik="";
    for(int i=0;i<200;++i){
        int temp = obrocenie_liczby(liczby[i]);
        if(czy_jest_pierwsza(temp)){
            wynik+=to_string(liczby[i])+"\n";
        }
    }
    return wynik;
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
            wynik+=to_string(liczby_pierwsze[i])+"\n";
            ++ile;
        }
    }
    return "Illosc liczb z waga 1: "+to_string(ile)+"\n"+"\n"+wynik;
}


void wyniki(const char* sciezka, int liczby_pierwsze[],string wynik){
    fstream plik;
    plik.open(sciezka,ios_base::out);
    if(plik.is_open()){
        plik<<wynik<<endl;
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

    const char* wyniki1 = "./odpowiedzi/wyniki4_1.txt";
    const char* wyniki2 = "./odpowiedzi/wyniki4_2.txt";
    const char* wyniki3 = "./odpowiedzi/wyniki4_3.txt";

    wczytaj(sciezka1, liczby);
    wczytaj(sciezka2, liczby_pierwsze);

    wyniki(wyniki1,liczby,polaczenie_przedzialu_i_pierwszej(liczby));
    wyniki(wyniki2,liczby_pierwsze,polaczenie_obrotu_i_pierwszej(liczby_pierwsze));
    wyniki(wyniki3,liczby_pierwsze,ile_wag_ktore_rownaja_sie_1(liczby_pierwsze));
}