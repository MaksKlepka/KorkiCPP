#include <iostream>
using namespace std;

int zwiekszO2(int* wskliczba)
{
    *wskliczba+=2;
    return *wskliczba;
}

int main()
{
    //zmienne statyczne
    {
        int liczbaS1; //deklaracja    
        liczbaS1=20; //inicjacja    
        int liczbaS2=10; //deklaracja i inicjacja    
        char literaS = 'a';

        cout<<"S1 = "<<liczbaS1<<endl;
        cout<<"S1 = "<<liczbaS1<<endl;
        cout<<"S1 = "<<liczbaS1<<endl;
        cout<<"S2 = "<<liczbaS2<<endl;
        cout<<"litera = "<<literaS<<endl;

    }    

    int* wsk = nullptr;
    //zmienne dynamiczne
    {
        int* liczbaD1 = new int; //deklaracja dynamiczna
        cout<<"adres = "<<liczbaD1<<endl;
        *liczbaD1=21; //wyluskanie wartosci
        cout<<"zawartosc adresu = "<<*liczbaD1<<endl;
        wsk=liczbaD1;

        int liczbaS1 = 7;
        int* wsk1DoS1 = &liczbaS1; //pozyskanie adresu
        int* wsk2DoS1 = wsk1DoS1;
        *wsk2DoS1 = 11;
        cout<<"S1 = "<<liczbaS1<<endl;       
    }
    cout<<"zawartosc adresu = "<<*wsk<<endl;
    delete wsk; //usuniecie z pamieci

    //przyklad
    int liczba = 0;
    cout<<"liczba+ = "<<zwiekszO2(&liczba)<<endl;
    cout<<"liczba+ = "<<zwiekszO2(&liczba)<<endl;
    cout<<"liczba+ = "<<zwiekszO2(&liczba)<<endl;

    
    
    
    


    return 0;
}