#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
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

bool czyPierwsza(int n){
    int s = sqrt(n);
    for(int i=2 ; i<s ; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

void goldbach(int n){
    if(n%2!=0){
        return;     //sprawdza czy liczba jest parzysta
    }
    int num1=0, num2=0;
    for(int i=3; i<=n ; i++){
        int r=n-i;
        if((czyPierwsza(i)&&czyPierwsza(r))&&(num2-num1<=r-i)){
            num2=r;
            num1=i;
        }
    }
    cout<<n<<" "<<num1<<" "<<num2<<endl;
}

int main()
{
    int liczby[100];
    string slowa[100];
    const char* sciezka = "./dane/przyklad.txt";

    wczytaj(sciezka,liczby,slowa);

    

    return 0;
}