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

int* kopiaTd(int tab[],int size)
{
    int* kopia = new int(size);
    for (int i=0;i<size;i++)
    {
        kopia[i]=tab[i];
    }
    return kopia;
}

void kopiaTs(int tab[],int kopia[],int size)
{    
    for (int i=0;i<size;i++)
    {
        kopia[i]=tab[i];
    }   
}

//napisać funkcję zamieniającą miejscami dwie liczby
void zamien(int* a,int* b)
{
    int temp=*b;
    *b=*a;
    *a=temp;
}

void sortowanie_babelkowe(int liczby[],int ile){
    for(int i=0;i<ile;i++){
        for(int j=1;j<ile-i;j++){
            if(liczby[j-1]<liczby[j])
                zamien(&liczby[j-1],&liczby[j]);
        }
    }
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

string zad_4_3(int liczby1[],int liczby2[],int ile1,int ile2){
    stringstream wynik;
    for(int i=0;i<ile2;i++){
        int badanaLiczba=liczby2[i];
        for(int j=0;ile1 && liczby1[j]<liczby2[i];j++){
            if (badanaLiczba%liczby1[j]==0)
            {
                badanaLiczba/=liczby1[j];
            }
            if (badanaLiczba==1)
            {
                wynik<<liczby2[i]<<" ";
                break;
            }            
        }
    }
    return wynik.str();
}

float srednia_arytmetyczna(int liczby[],int pierwszy_element_ciagu,int illosc_elementow){
    float wynik=0;
    for(int i=0;i<illosc_elementow;i++){
        wynik=wynik+liczby[pierwszy_element_ciagu+i];
    }
    return wynik/illosc_elementow;
}

float wieksza_srednia_arytmetyczna(float max_srednia, int max_dlugosc, int liczby[]){
    float wynik = max_srednia*max_dlugosc;
    wynik += liczby[max_dlugosc];
    wynik /= (max_dlugosc+1);
    return wynik;
}

void zadanie_4_4(int liczby[], int ile){
    float max_srednia = srednia_arytmetyczna(liczby,0,50);
    int max_poczatek_liczba = 0;//wyrazone jako indeks liczby, liczby[max_poczatek_liczba]
    int max_dlugosc = 50;//aby dostac ostatni wyraz ciagu, max_poczatek_liczba + max_dlugosc
    int licz = 0;
    stringstream wynik;
    
    while(licz<ile){
        if(wieksza_srednia_arytmetyczna(max_srednia,max_dlugosc,liczby)>=max_srednia){
            max_srednia=wieksza_srednia_arytmetyczna(max_srednia,max_dlugosc,liczby);
            max_dlugosc++;
        }
        else{
            for(;;){

            }
        }
        licz++;
    }
    cout<<max_srednia;
}

void zapisz1(const char* sciezka, int wynik){
    fstream plik;
    plik.open(sciezka,ios_base::out);
    if(plik.is_open()){
        plik<<"Zadanie 4.1"<<endl<<endl;
        plik<<"Ilosc dzielnikow: ";
        plik<<wynik<<endl<<endl;
    }
    else{
        cout<<"Plik wpisujacy sie nie otworzyl!";
    }
    plik.close();
}

void zapisz2(const char* sciezka, int liczby[], int ile){
    fstream plik;
    plik.open(sciezka,ios_base::app);
    if(plik.is_open()){
        sortowanie_babelkowe(liczby,ile);
        plik<<"Zadanie 4.2"<<endl<<endl;
        plik<<"Sto pierwsza liczba: ";
        plik<<liczby[100]<<endl<<endl;
    }
    else{
        cout<<"Plik wpisujacy sie nie otworzyl!";
    }
    plik.close();
}

void zapisz3(const char* sciezka, int liczby1[], int liczby2[], int ile1, int ile2){
    fstream plik;
    plik.open(sciezka,ios_base::app);
    if(plik.is_open()){
        plik<<"Zadanie 4.3"<<endl<<endl;
        plik<<zad_4_3(liczby1, liczby2, ile1, ile2)<<endl<<endl;
    }
    else{
        cout<<"Plik sie nie otworzyl!";
    }
    plik.close();
}

void zapisz4(){

}
 
int main(){
    int liczby1[3000];
    //dynamicznie
    //int* kopia1=kopiaTd(liczby1,3000);
    //statycznie
    //int kopia2[3000];
    //kopiaTs(liczby1,kopia2,3000);
    //int liczby1p[200];
    int liczby2[20];

    const char* sciezka_wczytaj = "./Dane/liczby.txt";
    //const char* sciezka_wczytajp = "./Dane/liczby_przyklad.txt";
    const char* sciezka_zapisz = "./Odpowiedzi/wyniki4.txt";
    
    wczytaj(sciezka_wczytaj,liczby1,liczby2,3000);
    zapisz1(sciezka_zapisz,ile_dzielnikow(liczby1,liczby2,3000));
    zapisz2(sciezka_zapisz,liczby1,3000);
    //zapisz3(sciezka_zapisz,liczby1,liczby2,3000,20);
    wczytaj(sciezka_wczytaj,liczby1,liczby2,3000);
    zadanie_4_4(liczby1,3000);
    return 0;
    
}