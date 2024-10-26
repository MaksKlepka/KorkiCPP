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
    wynik<<n<<" "<<num1<<" "<<num2<<endl;
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
    cout<<longest<<" "<<longest.length()<<endl;
    wynik<<longest<<" "<<longest.length()<<endl;
    return wynik.str();
}


//napisz funkcje czy mniejszy napis
bool czy_mniejszy_napis(string n1,string n2)
{
    
}


bool czy_mniejsza_para(string s1, string s2, int i1, int i2){

    int num1=i1, num2=i2;
    string word1=s1, word2=s2;

    if(num2>num1){ // porownujemy najpierw liczby
		return true;
	}
	else if(num1 == num2 && word2>word1){ // jezeli sa rowne to porwonujemy wyrazy
        return true;
	}
	return false;
}




string najmniejsza_para(int liczby[],string slowa[]){
    stringstream wynik;
    string para_tekst=slowa[0]; //Importujemy tekst z tabeli slowa
    int para_liczba=liczby[0]; //Importujemy liczbe z tabeli slowa

        for(int i=1;i<100; i++){
            if (liczby[i]==slowa[i].length())
            {
                if(czy_mniejsza_para(slowa[i], para_tekst, liczby[i], para_liczba))
                { //sprawdzamy ktory jest najmniejszy
			    para_tekst=slowa[i]; //zapisujemy odpowiedzi
                para_liczba=liczby[i]; //zapisujemy odpowiedzi
		        }
            }            
        }

	cout<<para_liczba<<" "<<para_tekst<<endl;
    wynik<<para_liczba<<" "<<para_tekst<<endl;  // zapisujemy wynik
	return wynik.str(); //wynik wyjdzie 3 asq, wiem czemu ale nie wiem jak rozwiazac ten problem. 
}

void zapisz1(const char* sciezka,int liczby[]){
    int i=0;
    fstream plik;
    plik.open(sciezka,ios_base::out);
            plik<<"Zadanie 4.1"<<endl;
            while(i!=100)
            {
                if(goldbach(liczby[i])!=""){
                    plik<<goldbach(liczby[i]);
                    ++i;
                }
                else{
                    ++i;
                }
            }
    plik.close();
    return;
}

void zapisz2(const char* sciezka, string slowa[]){
    int i=0;
    fstream plik;
    plik.open(sciezka,ios_base::app);
    plik<<endl<<"Zadanie 4.2"<<endl;
        while(i<100)
        {
            plik<<znadz_najdluszy_ciag(slowa[i]);
            ++i;
        }
    plik.close();
    return;
}

int main()
{
    int liczby[100];
    string slowa[100];

    const char* sciezka1 = "./dane/pary.txt";   //potrzebny do wpisania danych
    const char* sciezka2 = "./odpowiedzi/wyniki4.txt";    //potrzebny do zapisu danych

    wczytaj(sciezka1,liczby,slowa);
    zapisz1(sciezka2,liczby);
    zapisz2(sciezka2,slowa);
    najmniejsza_para(liczby,slowa);

    return 0;
}