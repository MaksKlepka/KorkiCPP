#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

vector<int*>& wczytajCiezarowki(const char* sciezka)
{
    fstream plik;    
    plik.open(sciezka,ios_base::in);
    vector<int*>& ciezarowki=*new vector<int*>;
    if(plik.is_open())
    {
        int i=1;
        while(!plik.eof())
        {
            int* ciezarowka = new int[3];
            ciezarowka[0]=i++;
            plik>>ciezarowka[1]>>ciezarowka[2];
            ciezarowki.push_back(ciezarowka);         
        }
        plik.close();        
    }
    else
    {
        cout<<"Plik sie nie otworzyl do odczytu!";
    }
    return ciezarowki;
}

void zapiszWyniki(const char* sciezka, string wynik)
{
    fstream plik;    
    plik.open(sciezka,ios_base::out);
    if(plik.is_open())
    {
        plik<<wynik;
        plik.close();        
    }
    else
    {
        cout<<"Plik sie nie otworzyl do zaoisu!";
    }
}

void usunCiezarowki(vector<int*>& ciezarowki)
{
    for(unsigned int i=0;i<ciezarowki.size();++i)
    {
        delete[] ciezarowki.at(i);
    }
    delete &ciezarowki;
}

void wypiszCiezarowki(vector<int*>& ciezarowki)
{
    for(unsigned int i=0;i<ciezarowki.size();++i)
    {
        cout<<"c"<<ciezarowki.at(i)[0]<<": "<<ciezarowki.at(i)[1]<<" "<<ciezarowki.at(i)[2]<<endl;
    }
}

string zadanie_1(vector<int*>& ciezarowki)
{
    stringstream wynik;    
    unsigned int ileKolumn=1;
    int dlgMax=0;
    int dlg=1;
    int spwMax=0;
    int spw=0;
    int vMin=ciezarowki.at(ciezarowki.size()-1)[2];
    for (int i=(ciezarowki.size()-2);i>=0;--i)
    {
       if (ciezarowki.at(i)[2]<=vMin)
       {
           vMin=ciezarowki.at(i)[2];
           ++ileKolumn;
           if (dlg>dlgMax)
           {
               dlgMax=dlg;
           }
           dlg=1;
       }
       else
       {
            ++dlg;
            spw=ciezarowki.at(i)[2]-vMin;
            if (spw>spwMax)
            {
                spwMax=spw;
            }
       }
    }
    wynik<<"----------------------------------------------------------------------\n";
    wynik<<"Zadanie 1.1\n";
    wynik<<"----------------------------------------------------------------------\n";
    wynik<<"Liczba kolumn: "<<ileKolumn<<endl;
    wynik<<"----------------------------------------------------------------------\n";
    wynik<<"Zadanie 1.2\n";
    wynik<<"----------------------------------------------------------------------\n";
    wynik<<"Najdluzsza kolumna liczy "<<dlgMax<<" pojazdow"<<endl;
    wynik<<"----------------------------------------------------------------------\n";
    wynik<<"Zadanie 1.3\n";
    wynik<<"----------------------------------------------------------------------\n";
    wynik<<"Najwieksze spowolnienie pojazdu: "<<spwMax<<endl;
    return wynik.str();
}


int main()
{
    const char* sc_wczytaj="./dane/BIT18.txt";
    const char* sc_zapisz="./odpowiedzi/wyniki1.txt";
    vector <int*>& ciezarowki=wczytajCiezarowki(sc_wczytaj);

    //wypiszCiezarowki(ciezarowki);
    string wynik1=zadanie_1(ciezarowki);
    cout<<wynik1<<endl;
    zapiszWyniki(sc_zapisz,wynik1);
    
    usunCiezarowki(ciezarowki);
    return 0;    
}
