#include <iostream>
using namespace std;


/* to jest podpunkt (A) */
long int rownanieA(long int n){
long int a=n, b=n;
do
{
    do{
    if(a*a+b*b==n){
        cout<<a<<"^2 + "<<b<<"^2 = "<<n<<endl;
        a--;
    }
    else{
        a--;
    }
    }while(a!=0);
    b--;
    a=n;
}while(a&&b!=0);
return 0;
}


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

int main(){
    long int n;
    cout<<"Program wypisuje wszystkie mozliwe rozklady liczby n na sumy dwoch kwadratow. Prosze podac liczbe n: ";
    cin>>n;
    cout<<"Rownania, uzywajac sposobu (a) to:"<<endl;
    rownanieA(n);
    cout<<"Rownania, uzywajac sposobu (b) to:"<<endl;
    rownanieB(n);
    return 0;
}