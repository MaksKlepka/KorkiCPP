#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void wczytaj(const char* sciezka,int liczby[],string slowa[])
{
    fstream plik;
    plik.open(sciezka,ios_base::in|ios_base::out);
    if (plik.is_open())
    {
        int i=0;
        while (!plik.eof())
        {
                plik>>liczby[i];
                plik>>slowa[i];
                ++i;
        }
        plik.close();
    }
    else
    {
        cout<<"!!!!!!!!"<<endl;
    }


}

int main(){
    int liczby[100];
    string slowa[100];
    const char* sciezka = "./dane/przyklad.txt";

    wczytaj(sciezka,liczby,slowa);

    

    return 0;
}