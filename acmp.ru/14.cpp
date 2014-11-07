#include <fstream>  
void main(){
	int a,b,c,d;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>a>>b;
	d=a*b;
	while (b) {
		c=b;
		b=a%b;
		a=c;
	}
	c=d/a;
	fout<<c;
}