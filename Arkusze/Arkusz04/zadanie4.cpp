#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int* utworz(int size)
{
    int* tab = new int[size];
    for (int i=0;i<size;++i)
    {
        *(tab+i)=0;
    }
    return tab;
}

void wczytaj(const char* sciezka,int* liczby1,int* liczby2,int ile)
{
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open())
    {
        int i = 0;        
        while(i<ile)
        {
            plik>>liczby1[i];
            ++i;
        }
        i=0;
        while(i<20)
        {
            plik>>liczby2[i];           
            ++i;
        }
        plik.close();
    }
    else
    {
        cout<<"Plik sie nie otworzyl do odzczytu!"<<endl;
    }
}

void zapisz(const char* sciezka,string odpowiedz,char opt='N')
{
    fstream plik;
    if (opt=='N')
        plik.open(sciezka,ios_base::out);
    else
        plik.open(sciezka,ios_base::app);
    if (plik.is_open())
    {
        plik<<odpowiedz;
        plik.close();
    }
    else
    {
        cout<<"Plik sie nie otworzyl do zapisu!"<<endl;
    }
}

void wypisz(int* liczby,int ile,string nazwa)
{
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<nazwa<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    for(int i=0;i<ile;i++)
    {
        cout<<liczby[i]<<" ";
        if ((i+1)%10==0) cout<<endl;
    }
    cout<<endl;
}

string zad4_1(int* liczby1,int* liczby2,int size)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    wynik<<"ZADANIE 4_1\n";
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    int ile=0;
    for (int i=0;i<size;++i)
    {
        for (int j=0;j<20;++j)
        {
            if (liczby2[j]%liczby1[i]==0)
            {
                ++ile;
                break;
            }
        }
    }
    wynik<<"Liczba dzielnikow w pierwszym wierszu: "<<ile<<endl;
    return wynik.str();
}

int* uporzadkowanaKopia(int* liczby,int size)
{
    int* kopia=new int[size];
    *kopia=*liczby;
    for (int i=1;i<size;++i)
    {
        int pom=*(liczby+i);
        int j=i-1;
        while (j>=0&&kopia[j]<pom)
        {
            kopia[j+1]=kopia[j];
            --j;
        }
        kopia[j+1]=pom;
    }
    return kopia;
}

string zad4_2(int* kopia, int size)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    wynik<<"ZADANIE 4_2\n";
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    wynik<<"101 w kolejnosci liczac od najwiekszej: "<<kopia[100]<<endl;
    return wynik.str();
}

bool czyIloczyn(int* kopia,int size,int liczba)
{
    int i=0;
    while (kopia[i]>liczba) ++i;
    for (int j=i;j<size;++j)
    {
        if (liczba%kopia[j]==0)
        {
            liczba/=kopia[j];
        }
        if (liczba==1) return true;
    }
    return false;
}

string zad4_3(int* kopia,int* liczby2,int size)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    wynik<<"ZADANIE 4_3\n";
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    wynik<<"Daja sie przedstawic w postaci iloczynu: ";
    for (int i=0;i<20;++i)
    {
        if (czyIloczyn(kopia,3000,liczby2[i]))
        {
            wynik<<liczby2[i]<<" ";
        }
    }
    wynik<<endl;
    return wynik.str();
}

long double srednia(int* liczby,int start,int ile=50)
{
    long double sr = 0.0;
    for (int i=start;i<start+50;++i)
    {
        sr+=liczby[i];
    }
    return sr/ile;
}

long double srednia(long double sr,int ile, int kolejny)
{
    return (sr*ile+kolejny)/(ile+1);
}

string zad4_4(int* liczby,int size)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    wynik<<"ZADANIE 4_4\n";
    wynik<<"--------------------------------------------------------------------------------------------------\n";
    int max_start=0;
    int max_ile=0;
    long double max_sr=0.0;
    for (int i=0;i<size-49;++i)
    {
        int start=i;
        int ile=50;
        long double sr=srednia(liczby,i);
        if (sr>max_sr)
        {
            max_start=start;
            max_ile=ile;
            max_sr=sr;
        }        
        for (int j=i+50;j<size;++j)
        {
            sr=srednia(sr,ile,liczby[j]);
            ++ile;
            if (sr>max_sr)
            {
                max_start=start;
                max_ile=ile;
                max_sr=sr;
            }        
        }
    }
    wynik<<"nawyzsza srednia: "<<max_sr<<endl;
    wynik<<"liczba elementow: "<<max_ile<<endl;
    wynik<<"pierwszy element: "<<liczby[max_start]<<" (na pozycji "<<max_start+1<<")\n";
    return wynik.str();
}

int main()
{
    int* liczby1=utworz(3000);
    wypisz(liczby1,3000,"liczby1");
    int* liczby2=utworz(20);
    wypisz(liczby2,20,"liczby2");

    const char* sciezka_wczytaj = "./dane/liczby.txt";
    //const char* sciezka_wczytajp = "./dane/liczby_przyklad.txt";
    const char* sciezka_zapisz = "./odpowiedzi/wyniki4.txt";

    wczytaj(sciezka_wczytaj,liczby1,liczby2,3000);
    wypisz(liczby1,3000,"liczby1");
    wypisz(liczby2,20,"liczby2");

    zapisz(sciezka_zapisz,zad4_1(liczby1,liczby2,3000));
    int* kopia=uporzadkowanaKopia(liczby1,3000);
    wypisz(kopia,3000,"Kopia");
    zapisz(sciezka_zapisz,zad4_2(kopia,3000),'A');
    zapisz(sciezka_zapisz,zad4_3(kopia,liczby2,3000),'A');
    zapisz(sciezka_zapisz,zad4_4(liczby1,3000),'A');

    delete [] kopia;
    delete [] liczby2;
    delete[] liczby1;
    return 0; 
}
