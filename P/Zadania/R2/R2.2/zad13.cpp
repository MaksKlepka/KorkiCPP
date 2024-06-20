#include <iostream>
using namespace std;

int rownanie(int n){
int a=n, b=n;

do
{
if(a*a+b*b==n){
    cout<<a<<"^2+"<<b<<"^2";
    a--;
}
else{
    a--;
}

if(a*a+b*b==n){
    cout<<a<<"^2+"<<b<<"^2";
    b--;
}
else{
    b--;
}
}while(a&&b!=0);
return 0;
}

int main(){
    int n;
    cout<<"Program wypisuje wszystkie mozliwe rozklady liczby n na sumy dwoch kwadratow. Prosze podac liczbe n: ";
    cin>>n;
    cout<<"Rownania to:"<<endl;
    rownanie(n);
    return 0;
}