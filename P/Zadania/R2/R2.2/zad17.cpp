#include <iostream>
using namespace std;

void zlicz(){
static unsigned int liczba=0;
    liczba++;
    cout<<"Funkcja zoztala wylowana "<<liczba<<" razy";
}

int main(){
    zlicz();
}