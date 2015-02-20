#include<iostream>
#include<windows.h>
using namespace std;

class B1{
int a;
public:
B1(int x=0) { a=x; }
void show_B1() { cout<<"B1=   "<< a <<"\n"; }
};

class B2{
int b;
public:
B2(int x=0) { b=x; }
void show_B2() { cout<<"B2=   "<< b <<"\n"; }
};

class D1: private B1, public B2{
int c;
public:
D1(int x, int y, int z) : B1(y), B2(z) { c=x;};
void show_D1() { cout<<"D1=  "<< c <<"\n"; show_B1(); show_B2();}
};

class D2: public D1{
int d;
public:
D2(int x, int y, int z, int i) : D1(y,z,i) { d=x;};
void show_D2() { cout<<"D2=  "<< d <<"\n";  show_D1();}
};

class D3: private D1{
int e;
public:
D3(int x, int y, int z, int i) : D1(y,z,i) { e=x;}
void show_D3() { cout<<"D3=  "<<e <<"\n"; show_D1();}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	D2 temp(100,200,300,400);
	D3 temp1(1,2,3,4);
	cout<<"D2 temp(100,200,300,400);\n";
	cout<<"D3 temp1(1,2,3,4);\n";
	cout<<"\n Следуя иерархии класса D2: \n";
	temp.show_D2();
	cout<<"\n Следуяи ерархии класса D3: \n";
	temp1.show_D3();
	cout<<"\n\n";
	system("pause");
	return 0;
}
