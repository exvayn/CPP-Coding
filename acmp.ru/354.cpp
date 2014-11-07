#include <fstream>
#include <cmath>
void main(){
	int n,i=2,j,k,s=0;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	while(i<=sqrt((float)n) && n!=1){
		if (!(n%i)) {fout<<i<<"*"; n=n/i; i=1;}
		i++;
	}
	fout<<n;
}