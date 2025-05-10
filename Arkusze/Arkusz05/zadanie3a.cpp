#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void wczytaj(const char* sciezka,unsigned int* wz,string* szyfr,unsigned int ile=10)
{
    fstream plik;
    plik.open(sciezka, ios::in);
    if (plik.is_open())
    {
        for (unsigned int i = 0; i < ile; i++)
        {
            plik>> wz[i];
            plik>> szyfr[i];
        }
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku!" << endl;        
    }
}

template<typename T> void wypisz(T* tab, unsigned int ile=10)
{
    for (unsigned int i = 0; i < ile; i++)
    {
        cout<<"--------------------"<<endl;
        cout<<"Szyfrogram nr "<<i+1<<endl;
        cout<<"--------------------"<<endl;
        cout << tab[i] << endl;
    }
}

// Zadanie 3.1 (funkaja pomocnicza)
void wstawAlfabetycznie(vector<string>& unikalne, string nowyWzorzec)
{
    unsigned int i = 0;
    while (i < unikalne.size() && unikalne[i] < nowyWzorzec)
    {
        i++;
    }
    unikalne.insert(unikalne.begin() + i, nowyWzorzec);
}

// Zadanie 3.1 (funkcja pomocnicza)
vector<string>& wyszukajUnikalne(string szyfrogram,unsigned int dlg_wzorca)
{
    vector<string>& unikalne=*new vector<string>;
    unikalne.push_back(szyfrogram.substr(0, dlg_wzorca));
    for (unsigned int i = 1; i < szyfrogram.length()-dlg_wzorca+1; i++)
    {
        string nowyWzorzec=szyfrogram.substr(i, dlg_wzorca);
        bool czyUnikalny=true;
        for (unsigned int j = 0; j < unikalne.size(); j++)
        {
            if (unikalne[j] == nowyWzorzec)
            {
                czyUnikalny=false;
                break;
            }
        }
        if (czyUnikalny)
        {
            wstawAlfabetycznie(unikalne, nowyWzorzec);
        }       
    }
    return unikalne;
}

void zadanie_3_1(string szyfrogram, unsigned int dlg_wzorca)
{
    vector<string>& unikalne = wyszukajUnikalne(szyfrogram, dlg_wzorca);
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Zadanie 3.1"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Szyfrogram: "<<szyfrogram<<";\nunikalne wzorce o dlugosci "<<dlg_wzorca<<": " << endl;
    for (unsigned int i = 0; i < unikalne.size(); i++)
    {
        cout <<i+1<<")\t"<<unikalne[i] << endl;
    }
    delete &unikalne;
}

// Zadanie 3.2, Zadanie 3.3 (funkcja pomocnicza)
bool czyRozneZnaki(string tekst)
{
    char znak = tekst[0];
    for (unsigned int i=1;i<tekst.size();++i)
    {
        if (znak!=tekst[i]) return true;
    }
    return false;
}

// Zadanie 3.2 (funkcja pomocnicza)
unsigned int ileUnikalnych(string szyfrogram, unsigned int dlgWzorca)
{
    vector<string> wzorce;
    for (unsigned int i=0;i<szyfrogram.size()-dlgWzorca+1;++i)
    {
        string nowyWzorzec=szyfrogram.substr(i,dlgWzorca);
        if (czyRozneZnaki(nowyWzorzec))
        {
            if (wzorce.size()==0)
                wzorce.push_back(nowyWzorzec);
            else
            {
                bool czyUnikalny=true;
                for (unsigned int j=0;j<wzorce.size();++j)
                {
                    if (wzorce[j]==nowyWzorzec)
                    {
                        czyUnikalny=false;
                        break;
                    }                        
                }
                if (czyUnikalny)
                {
                    wzorce.push_back(nowyWzorzec);
                }
            }
        }
    }
    return wzorce.size();
}

void zadanie_3_2(string* szyfrogramy,unsigned int* wzorce,unsigned int ile=10)
{
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Zadanie 3.2"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    for (unsigned int i=0;i<ile;++i)
    {
        unsigned int ileWzorcow=ileUnikalnych(szyfrogramy[i],wzorce[i]);
        cout<<"Szyfrogram nr "<<i+1<<", dlugosc wzorca "<<wzorce[i]<<": "<<ileWzorcow<<" unikalnych wzorcow."<<endl;
    }
    cout<<"--------------------------------------------------------------------------------"<<endl;
}

// Zadanie 3.3 (funkcja pomocnicza)
void dodajWzorzec(vector<string>& wzorce,string wzorzec,vector<unsigned int>& liczbaWystapien)
{
    if (czyRozneZnaki(wzorzec))
    {
        if (wzorce.size()==0)
        {
            wzorce.push_back(wzorzec);
            liczbaWystapien.push_back(1);
            
        }
        for (unsigned int i=0;i<wzorce.size();++i)
        {
            if (wzorce[i]==wzorzec)
            {
                ++liczbaWystapien[i];
            }
        }
        wzorce.push_back(wzorzec);
        liczbaWystapien.push_back(1);
    }
}

void zadanie_3_3(string* szyfrogramy,unsigned int dlg_wzorca=8,unsigned int ile=10)
{
    vector<string> wzorce;
    vector<unsigned int> liczbaWystapienWzorca;
    for (unsigned int i=0;i<ile;++i)
    {
        for (unsigned int j=0;j<szyfrogramy[i].size()-dlg_wzorca+1;++j)
        {
            string nowyWzorzec=szyfrogramy[i].substr(j,dlg_wzorca);
            dodajWzorzec(wzorce,nowyWzorzec,liczbaWystapienWzorca);
        }
    }
    unsigned int indexMax=0;
    unsigned int max=0;
    for (unsigned int i=0;i<liczbaWystapienWzorca.size();++i)
    {
        unsigned int ileW=liczbaWystapienWzorca[i];
        if (ileW>max)
        {
            max=ileW;
            indexMax=i;
        }
    }
    cout<<"Zadanie 3.3"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Najczesciej wystepujacy wzorzec o dlugosci 8 znakow: "<<wzorce[indexMax]<<"; wystepuje "<<max<<" razy."<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
}

int main()
{
    unsigned int ile = 10;
    const char* sciezka = "./dane/szyfrogram.txt";
    unsigned int* wzorce = new unsigned int[ile];
    string* szyfrogramy = new string[ile];

    wczytaj(sciezka, wzorce, szyfrogramy, ile);
    string szyfrogram = "DEDOFKDEDOF";
    //wypisz(szyfrogramy);
    //wypisz(wzorce);
    
    zadanie_3_1(szyfrogram, 3);
    zadanie_3_2(szyfrogramy,wzorce);
    zadanie_3_3(szyfrogramy);

    delete[] wzorce;
    delete[] szyfrogramy;
    return 0;
}