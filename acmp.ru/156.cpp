#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,n,c,x,k;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n>>k;
	c=1;
	x=1;
	for (i=0;i<k;i++){
		c=c*(n-i)*(n-i);
		x=x*(i+1);
	}
	fout<<((int)(c/x));
}