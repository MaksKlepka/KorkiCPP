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

/* to bedzie podpunkt (B) */
long int rownanieB(long int n){

return 0;
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