#include <iostream>
using namespace std;

int main()
{
int liczba;
cout<<"Podaj liczbe: "; cin>>liczba;
cout<<"Twoja liczba + 1 to: "<<liczba+1<<endl;
//operatory prefiksowe i postfiksowe
//liczba=liczba+1;
//liczba+=1;
//liczba*=2;
//++liczba;
//liczba++;
//--liczba;
//liczba--;
int x = 1;
int y;
cout<<"x = "<<++x<<endl;
cout<<"x = "<<x++<<endl;
cout<<"x = "<<--x<<endl;
cout<<"x = "<<x--<<endl;
cout<<"x = "<<x<<endl;
y=x++;
y=++x;
return 0;
}