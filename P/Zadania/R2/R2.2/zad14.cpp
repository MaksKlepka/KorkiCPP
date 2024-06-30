#include <iostream>
#include <stack>
using namespace std;

int pierw(unsigned int x){
    int pocz=0, kon=x, sr;
    while(kon-pocz>1){
        sr=(pocz+kon)/2;
        if(sr*sr<=x)
            pocz=sr;
        else
            kon=sr;
    }
    if(x<=1)
        return kon;
    else
        return pocz;
}

/* to jest podpunkt (B) */
void rownanieB(unsigned int n){
    int i, p;
    for(i=1;i<=pierw(n);i++){
        p=pierw(n-i*i);
        if((i*i+p*p==n)&&(i<p))
            cout<<i<<"^2 + "<<p<<"^2 = "<<n<<endl;
    }
}

int wypisanie(int n){
    stack<int> stack;
}

int main(){
    int n;
    cout<<"Program wypisuje wszystkie mozliwe rozklady liczby n na sumy kwadratow dodatnich liczb calkowitych. Prosze podac liczbe n: ";
    cin>>n;
    cout<<"Rownania: "<<endl;
    wypisanie(n);
    return 0;
}