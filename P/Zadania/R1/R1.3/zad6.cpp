#include <iostream>
using namespace std;

int main(){
    double a1, b1, c1, y1, a2, b2, c2, y2;
    cout<<"Dzien dobry. To jest program obliczajacy czy linia leza na sobie, przecinaja sie lub nie przecinaja sie."<<endl<<"prosze wpisac a1: ";
    cin>>a1;
    cout<<"Prosze wpisac b1: ";
    cin>>b1;
    cout<<"Prosze wpisac c1: ";
    cin>>c1;
    cout<<"Prosze wpisac a2: ";
    cin>>a2;
    cout<<"Prosze wpisac b2: ";
    cin>>b2;
    cout<<"Prosze wpisac c1: ";
    cin>>c2;

    y1=(a1*0+c1)/b1;
    y2=(a2*0+c2)/b2;

    if(a1*b2-a2*b1==0){
        if(y1==y2){
            cout<<"Proste leza na sobie"<<endl; //leza na sobie
            return 0;
        }
        cout<<"Proste sa rownolegle do siebie."<<endl; // nie przecinaja sie
        return 0;
    }
    else{
        cout<<"Proste sa prostopadle do siebie. Punkt przeciecia to: ("<<(b1*c2-b2*c1)/(a1*b2-a2*b1)<<","<<(c1*a2-c2*a1)/(a1*b2-a2*b1)<<")"; //przecinaja sie w 1 punktcie
        return 0;
    }
}