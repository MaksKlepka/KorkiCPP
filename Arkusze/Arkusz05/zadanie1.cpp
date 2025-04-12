#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int najwolniejsza_predkosc(vector<int>& predkosc);
void wczytaj(const char* sciezka,vector<int>& kilometer,vector<int>& predkosc);
int illosc_kolumn(vector<int>& predkosc);

int main(){
    vector <int> kilometer;
    vector <int> predkosc;
    vector <int[2]> ciezarowki;

    const char* scieszka_wczytaj="./dane/BIT18.txt";

    wczytaj(scieszka_wczytaj,kilometer,predkosc);
    /*for(int i=0; i<kilometer.size()&& i<predkosc.size(); i++)
    cout<<kilometer[i]<<" "<<predkosc[i]<<endl;*/
}

int najwolniejsza_predkosc(vector<int>& predkosc){
    int slowest_speed=predkosc.at(0);
    for(int i=1;i<predkosc.size();i++){
        if(predkosc.at(i)<slowest_speed){
            slowest_speed=predkosc.at(i);
        }
    }
    return slowest_speed;
}

void wczytaj(const char* sciezka,vector<int>& kilometer,vector<int>& predkosc){
    fstream plik;
    int km, pr;
    plik.open(sciezka,ios_base::in);
    if(plik.is_open()){
        while(plik>>km>>pr){
            kilometer.push_back(km);
            predkosc.push_back(pr);
        }
    }
    else{
        cout<<"Plik sie nie otworzyl i nie zapisuje!";
    }
    plik.close();
}

int illosc_kolumn(vector<int>& predkosc){
    int wynik=0;
    int slowest_speed=najwolniejsza_predkosc(predkosc);
    for(int i=predkosc.size();i>0;i--){
        if(predkosc.at(i)<predkosc.at(i-1)){

        }
    }
    return wynik;
}