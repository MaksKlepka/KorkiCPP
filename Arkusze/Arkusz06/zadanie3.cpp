#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

string* wczytaj(const char* sciezka,unsigned int ileElementow=1000)
{
    string* slowa=new string[ileElementow];
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if (plik.is_open())
    {
        for (unsigned int i=0;i<ileElementow;++i)
        {
            plik>>slowa[i];
        }
        plik.close();
    }
    else
    {
        cout<<"Blad przy otwieraniu pliku do odczytu!"<<endl;
    }
    return slowa;
}

void zapiasz(const char* sciezka,string tekst, char opt='a')
{
    fstream plik;
    if (opt=='n')
        plik.open(sciezka,ios_base::out);
    else
        plik.open(sciezka,ios_base::app);
    if (plik.is_open())
    {
        plik<<tekst;
        plik.close();
    }
    else
    {
        cout<<"Blad przy otwarciu pliku do zapisu!"<<endl;
    }
}

void wypisz(string* slowa,unsigned int ile=1000)
{
    for (unsigned int i=0;i<ile;++i)
    {
        cout<<i+1<<")\t"<<slowa[i]<<endl;
    }
}

// Zadanie 3.1 (funkcja pomocnicza)
bool czyJestTamKot(string slowo)
{
    for (unsigned int i=0;i<slowo.size()-2;++i)
    {
        string fragment=slowo.substr(i,3);
        if (fragment[0]=='k'&&fragment[2]=='t') return true;
    }
    return false;
}

// Zadanie 3.1
string zadanie_3_1(string* slowa,unsigned int ileE=1000)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------"<<endl;
    wynik<<"Zadanie 3.1"<<(ileE==10?" (slowa_przyklad.txt)":" (slowa.txt)")<<endl;
    wynik<<"--------------------------------------------------------------------------------"<<endl;
    unsigned int ileKotow=0;
    for (unsigned int i=0;i<ileE;++i)
    {
        if (czyJestTamKot(slowa[i])) ++ileKotow;
    }
    wynik<<"Fragment \"k?t\" wystepuje w "<<ileKotow<<" zbadanych slowach."<<endl;
    return wynik.str();
}

// Zadanie 3.2 (funkcja pomocnicza)
string rot13(string slowo)
{
    string wynik="";
    for (unsigned int i=0;i<slowo.size();++i)
    {
        int znak=(int)slowo[i];
        znak+=13;
        znak=(znak<=(int)'z'?znak:znak-26);
        wynik.push_back((char)znak);
        /*
        char znak=slowo[i]-32;
        znak+=13;
        znak=(znak>'Z'?znak-26:znak;)
        znak+=32;
        */
    }
    return wynik;
}

// Zadanie 3.2 (funkcja pomocnicza)
bool czyWspak(string slowo,string rot13)
{
    for (unsigned int i=0;i<slowo.size();++i)
    {
        if (slowo[i]!=rot13[rot13.size()-i-1]) return false;
    }
    return true;
}

// Zadanie 3.2
string zadanie_3_2(string* slowa,unsigned int ileE=1000)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------"<<endl;
    wynik<<"Zadanie 3.2"<<(ileE==10?" (slowa_przyklad.txt)":" (slowa.txt)")<<endl;
    wynik<<"--------------------------------------------------------------------------------"<<endl;
    unsigned int ileW=0;
    unsigned int maxDld=0;
    string najDlg="";
    for (unsigned int i=0;i<ileE;++i)
    {
        string sl=slowa[i];
        if (czyWspak(sl,rot13(sl)))
        {
            ++ileW;
            if (sl.size()>maxDld)
            {
                maxDld=sl.size();
                najDlg=sl;
            }
        }
    }
    wynik<<"Liczba slow, ktore można odczytac wspak po zakodowaniu: "<<ileW<<"."<<endl;
    wynik<<"Najdluzsze z nich to: \""<<najDlg<<"\"."<<endl;
    return wynik.str();
}

// Zadanie 3.3 (funkcja pomocnicza)
bool cnmPolowa(string slowo)
{
    unsigned int dlgSlowa=slowo.size();
    unsigned int polowa=dlgSlowa%2?dlgSlowa/2+1:dlgSlowa/2;
    while (slowo.size()>=polowa)
    {
        char znak=slowo[0];
        unsigned int ileZnakow=1;
        slowo.erase(0,1);
        unsigned int i=0;
        while (i<slowo.size())
        {
            if (slowo[i]==znak)
            {
                slowo.erase(i,1);
                ++ileZnakow;
            }
            else
            {
                ++i;
            }            
        }
        if (ileZnakow>=polowa) return true;        
    }
    return false;
}

// Zadanie 3.3
string zadanie_3_3(string* slowa,unsigned int ileE=1000)
{
    stringstream wynik;
    wynik<<"--------------------------------------------------------------------------------"<<endl;
    wynik<<"Zadanie 3.3"<<(ileE==10?" (slowa_przyklad.txt)":" (slowa.txt)")<<endl;
    wynik<<"--------------------------------------------------------------------------------"<<endl;
    unsigned int ileSl=0;
    string wybraneSL="";
    for (unsigned int i=0;i<ileE;++i)
    {
        if (cnmPolowa(slowa[i]))
        {
            ++ileSl;
            wynik<<ileSl<<")\t"<<slowa[i]<<endl;           
        }
    }
    wynik<<"Jest takich slow "<<ileSl<<":"<<endl;
    wynik<<wybraneSL;
    return wynik.str();
}

int main()
{
    const char* sciezka_op="./dane/slowa_przyklad.txt";
    const char* sciezka_o="./dane/slowa.txt";
    const char* sciazka_z="./odpowiedzi/wyniki3.txt";
    string* slowaP=wczytaj(sciezka_op,10);
    string* slowa=wczytaj(sciezka_o);
    //wypisz(slowaP,10);

    zapiasz(sciazka_z,zadanie_3_1(slowaP,10),'n');
    zapiasz(sciazka_z,zadanie_3_1(slowa));
    zapiasz(sciazka_z,zadanie_3_2(slowaP,10));
    zapiasz(sciazka_z,zadanie_3_2(slowa));
    zapiasz(sciazka_z,zadanie_3_3(slowaP,10));
    zapiasz(sciazka_z,zadanie_3_3(slowa));

    delete[] slowaP;
    delete[] slowa;
    return 0; 
}