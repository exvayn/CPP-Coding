#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,n;
	long long k=0;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	for (i=0;i<=n;i++)
		for (j=i;j<=n;j++)
			k+=i+j;
	fout<<k;
}