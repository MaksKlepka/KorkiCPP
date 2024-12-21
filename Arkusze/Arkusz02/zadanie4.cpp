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

//i - indels pierwszej liczby
int luka_pomiedzy_dwoma_liczbami(int liczby[], int i){
    int wynik = liczby[i]-liczby[i+1];
    if(wynik<0){
        wynik=wynik*(-1);
    }
    return wynik;
}

//1
int najwieksza_luka(int liczby[]){
    int wynik=luka_pomiedzy_dwoma_liczbami(liczby,0);
    int i=1;
    while(i<999){
        if(wynik<luka_pomiedzy_dwoma_liczbami(liczby,i)){
            wynik=luka_pomiedzy_dwoma_liczbami(liczby,i);           
        }
       ++i;
    }
    return wynik;
}

//1
int najmniejsza_luka(int liczby[]){
    int wynik=luka_pomiedzy_dwoma_liczbami(liczby,0);
    int i=1;
    while(i<999){
        if(wynik>luka_pomiedzy_dwoma_liczbami(liczby,i)){
            wynik=luka_pomiedzy_dwoma_liczbami(liczby,i); 
        }
        ++i;        
    }
    return wynik;
}

//2
string najdluszy_fragment_regularnej(int liczby[]){
    stringstream wynik;
    int count=2, count_max=2;
    int index_pierwszej_liczby = 0, index_pierwszej_max=0;
    int luka1=luka_pomiedzy_dwoma_liczbami(liczby,0);
    for(int i=1;i<999;i++){
        int luka2=luka_pomiedzy_dwoma_liczbami(liczby,i);
        if(luka2==luka1){
            count+=1;            
        }
        else{
            if (count>count_max)
            {
                count_max=count;
                index_pierwszej_max=index_pierwszej_liczby;
            }
            index_pierwszej_liczby=i;
            count=2;
            luka1=luka2;
        }
    }
    wynik<<"Najwieksza dlugosc fragmentu regularnego: "<<count_max<<endl;
    wynik<<"Poczatek: "<<liczby[index_pierwszej_max]<<endl;
    wynik<<"Koniec: "<<liczby[index_pierwszej_max+count_max-1]<<endl<<endl;
    return wynik.str();
}



//Kod porownuje podana luke do wszystkich innych luk, wtedy oddaje illosc wystapien tej luki (Krotnosc)
int krotnosc_luki(int liczby[], int n){
    int count=0;
    int luka_poruwnawscza=luka_pomiedzy_dwoma_liczbami(liczby,n);    //Podanna luka
    int i=0;
    while(i<999){
        if(luka_poruwnawscza==luka_pomiedzy_dwoma_liczbami(liczby,i)){   //porownanie podanej luki do wszyskich innych
            count+=1;
        }
        ++i;
    }
    return count;
}

string najczestsza_luka(int liczby[]){
    int czesc1=krotnosc_luki(liczby,0);
    int czesc2=luka_pomiedzy_dwoma_liczbami(liczby,0);
    stringstream wynik;

    for(int i=0;i<999;i++){
        if(krotnosc_luki(liczby,i)>czesc1){
            czesc1=krotnosc_luki(liczby,i);
            czesc2=luka_pomiedzy_dwoma_liczbami(liczby,i);
        }
    }

    wynik<<"Zadanie 4.3"<<endl;
    wynik<<"Krotnosc najczestszej luki: "<<czesc1<<endl;
    wynik<<"Wartosci najczestszych luk: "<<czesc2<<endl<<endl;
    return wynik.str();
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

void zapisz3(const char* sciezka, int liczby[]){
    fstream plik;
    plik.open(sciezka,ios_base::app);
    if(plik.is_open()){
        plik<<najczestsza_luka(liczby);
    }
    else{
        cout<<"Plik sie nie otworzyl!"<<endl;
    }
    return;
}

int main(){
    int liczby[1000];

    const char* sciezka1 = "./dane/dane4.txt";
    const char* sciezka2 = "./odpowiedzi/zadanie4.txt";

    wczytaj(sciezka1, liczby);
    zapisz1(sciezka2, liczby);
    zapisz2(sciezka2, liczby);
    zapisz3(sciezka2, liczby);
    return 0;
}