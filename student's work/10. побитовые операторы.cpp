#include <iostream>
#include <bitset>
using namespace std;
int main (void){
	int a,b,c;
	cout<<"Insert a b: ";
	cin>>a>>b;
	c=a&b;
	cout<<"\n\n"<<bitset<16>(a)<<" - "<<a;
	cout<<"\n"<<bitset<16>(b)<<" - "<<b;
	cout<<"\n"<<bitset<16>(c)<<" - "<<c;
	cout<<"\n\n"<<c<<"\n\n";
	system ("pause");
}
