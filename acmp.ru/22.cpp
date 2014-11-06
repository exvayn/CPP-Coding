#include <fstream>
void main(){
	int n,s=1;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	if (n==0) s=0; 
	else while (n>1){
		if (n%2==1) s++;
		n=n/2;
	}
		fout<<s;
}