#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b, c, delta, x1, x2;
    cin>>a;
    cin>>b;
    cin>>c;

    delta=(b^2)-4*a*c;

    cout<<"Delta rowna sie: "<<delta<<endl;

    if(delta>0){
        x1=(-b)-sqrt(delta)/2*a;
        x2=(-b)+sqrt(delta)/2*a;
        cout<<"Sa dwa miejsca zerowe. Te miejsca to: "<<x1<<" i "<<x2;
    }
    if(delta==0){
        x1=-(b/2*a);
        cout<<"jest jedno miejsce zerowe. To miejsce to: "<<x1;
    }
    if(delta<0){
        cout<<"funkcja nie ma miejsc zerowych";
    }
    return 0;
}