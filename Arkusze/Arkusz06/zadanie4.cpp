#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

unsigned int* wczytaj(const char* sciezka,unsigned int ileE=1024)
{
    unsigned int* odbiorcy=new unsigned int[ileE];
    fstream plik;
    plik.open(sciezka,ios_base::in);
    if (plik.is_open())
    {
        for (unsigned int i=0;i<ileE;++i)
        {
            plik>>odbiorcy[i];
        }
        plik.close();
    }
    else
    {
        cout<<"Blad przy otwarciu pliku do odczytu!"<<endl;
    }
    return odbiorcy;
}

void wypisz(unsigned int* odb,unsigned int ileE=1024)
{
    for (unsigned int i=0;i<ileE;++i)
    {
        cout<<i+1<<"\t->\t"<<odb[i]<<endl;
    }
}

void zadanie_4_2(unsigned int* odb,unsigned int ileE=1024)
{
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Zadanie 4.2"<<(ileE==16?" (odbiorcy_przyklad.txt)":" (odbiorcy.txt)")<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    bool* czyJestOdbiorca=new bool[ileE];
    for (unsigned int i=0;i<ileE;++i)
    {
        czyJestOdbiorca[i]=false;
    }
    for (unsigned int i=0;i<ileE;++i)
    {
        czyJestOdbiorca[odb[i]-1]=true;
    }
    unsigned int ileNotOdb=0;
    string notOdb="Komputery:\n";
    for (unsigned int i=0;i<ileE;++i)
    {
        if (!czyJestOdbiorca[i])
        {
            ++ileNotOdb;
            notOdb+=(to_string(i+1)+", ");            
        }
    }
    notOdb.pop_back();
    notOdb.pop_back();
    notOdb+="\nnie sa odbiorcami pakietow.";
    cout<<notOdb<<endl;
    cout<<"Jest ich "<<ileNotOdb<<"."<<endl;
    delete[] czyJestOdbiorca;
}

//funkcja pomocnicza do Zadania 4.3 i 4.4
void kolejnaRunda(unsigned int* odb,unsigned int* rnd,unsigned int ileE=1024)
{
    for (unsigned int i=0;i<ileE;++i)
    {
        rnd[i]=odb[rnd[i]-1];
    }
}

//funkcja pomocnicza do Zadania 4.3
unsigned int czyPowrocil(unsigned int* rnd,unsigned int ileE=1024)
{
    for (unsigned int i=0;i<ileE;++i)
    {
        if (rnd[i]==(i+1)) return i+1;
    }
    return 0;
}

void zadanie_4_3(unsigned int* odb,unsigned int ileE=1024)
{
    unsigned int* runda=new unsigned int[ileE];
    for (unsigned int i=0;i<ileE;++i)
    {
        runda[i]=odb[i];
    }
    unsigned int nrRnd=1;
    unsigned int pakiet=czyPowrocil(runda,ileE);
    while (pakiet==0)
    {
        kolejnaRunda(odb,runda,ileE);
        ++nrRnd;
        pakiet=czyPowrocil(runda,ileE);       
    }
    delete[] runda;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Zadanie 4.3"<<(ileE==16?" (odbiorcy_przyklad.txt)":" (odbiorcy.txt)")<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Pakiet "<<pakiet<<" powrocil w "<<nrRnd<<" rundzie."<<endl;
}

//funkcja pomocnicza do Zadania 4.4
unsigned int najwiecejPakietow(unsigned int* rnd,unsigned int ileE=1024)
{
    unsigned int* ileP=new unsigned int[ileE];
    for (unsigned int i=0;i<ileE;++i)
    {
        ileP[i]=0;
    }
    for (unsigned int i=0;i<ileE;++i)
    {
        ++ileP[rnd[i]-1];
    }
    unsigned int maxP=0;
    for (unsigned int i=0;i<ileE;++i)
    {
        if (ileP[i]>maxP) maxP=ileP[i];
    }
    delete[] ileP;
    return maxP;
}

void zadanie_4_4(unsigned int* odb,unsigned int ileE=1024)
{
    unsigned int* runda=new unsigned int[ileE];
    for (unsigned int i=0;i<ileE;++i)
    {
        runda[i]=odb[i];
    }
    unsigned int nrRnd=1;
    unsigned int maxP=najwiecejPakietow(runda,ileE);
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Zadanie 4.4"<<(ileE==16?" (odbiorcy_przyklad.txt)":" (odbiorcy.txt)")<<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Po "<<nrRnd<<" rundzie najwieksza liczba pakietow na jednym komputerze: "<<maxP<<endl;
    while (nrRnd<=8)
    {
        kolejnaRunda(odb,runda,ileE);
        ++nrRnd;
        if (nrRnd==2||nrRnd==4||nrRnd==8)
        {
            maxP=najwiecejPakietow(runda,ileE);
            cout<<"Po "<<nrRnd<<" rundzie najwieksza liczba pakietow na jednym komputerze: "<<maxP<<endl;
        }
    }
    delete[] runda;
}

int main()
{
    const char* sciezkaOP="./dane/odbiorcy_przyklad.txt";
    const char* sciezkaO="./dane/odbiorcy.txt";
    unsigned int* odbiorcyP=wczytaj(sciezkaOP,16);
    unsigned int* odbiorcy=wczytaj(sciezkaO);
    //wypisz(odbiorcyP,16);

    zadanie_4_2(odbiorcyP,16);
    zadanie_4_2(odbiorcy);
    zadanie_4_3(odbiorcyP,16);
    zadanie_4_3(odbiorcy);
    zadanie_4_4(odbiorcyP,16);
    zadanie_4_4(odbiorcy);

    delete[] odbiorcy;
    delete[] odbiorcyP;
    return 0;
}