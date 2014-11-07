#include <fstream>  
void main(){
	int i,j,k,n;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	if (n) for(i=j=k=1;i<n-1;i++,j+=k,k=j-k); else j=0;
	fout<<j;
}