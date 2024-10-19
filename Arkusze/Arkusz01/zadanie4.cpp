#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
    for(int i=2 ; i*i<n ; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

string goldbach(int n){
    stringstream wynik;
    if(n%2!=0){
        return "";     //sprawdza czy liczba jest parzysta
    }
    int num1=0, num2=0;
    for(int i=3; i<=n/2 ; i+=2){
        int r=n-i;
        if((czyPierwsza(i)&&czyPierwsza(r))&&(num2-num1<=r-i)){
            num2=r;
            num1=i;
        }
    }
    cout<<n<<" "<<num1<<" "<<num2<<endl;
    wynik<<n<<" "<<num1<<" "<<num2;
    return wynik.str();
}

string znadz_najdluszy_ciag(string slowo){
    stringstream wynik;
    string longest="";
    string current="";
    for(int i=0;i<slowo.length();i++){
        if(current.length()==0||current[0]==slowo[i]){ // jezeli aktualne slowo jest puste LUB iterowany znak ze slowa jest taki sam jak ten przechowany
            current+=slowo[i];
        }
        else{
            if(current.length()>longest.length()){ //sprawdz, czy aktualny ciag nie jest dluzszy niz ten zapisany
                longest=current; //jesli tak to zapisuje
            }
            current="";
            current+=slowo[i]; //zapisujemy aktualna lietke
        }
    }
    if(current.length()>longest.length()){ //sprawdz, czy aktualny ciag nie jest dluzszy niz ten zapisany
        longest=current;
    }
    if(longest.length()==0){ //w przypadku, gdy caly wyraz skladal sie z tej samej litery
        longest=current;
    }
    cout<<longest<<" "<<longest.length()<<endl;
    wynik<<longest<<" "<<longest.length()<<endl;
    return wynik.str();
}

void zapisz(const char* sciezka,int liczby[]){
    int i=0;
    fstream plik;
    plik.open(sciezka,ios_base::in|ios_base::out);
            while(i!=100)
            {
                if(goldbach(liczby[i])!=""){
                    plik<<goldbach(liczby[i])<<endl;
                    ++i;
                }
                else{
                    ++i;
                }
            }
    plik.close();
    return;
}



int main()
{
    int liczby[100];
    string slowa[100];

    const char* sciezka1 = "./dane/pary.txt";   //potrzebny do wpisania danych
    const char* sciezka2 = "./dane/wyniki4.txt";    //potrzebny do zapisu danych

    wczytaj(sciezka1,liczby,slowa);
    zapisz(sciezka2,liczby);
    znadz_najdluszy_ciag(slowa[1]);

    return 0;
}