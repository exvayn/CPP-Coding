#include <fstream>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,k=0,n,x;
	fin>>n;
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++){
			fin>>x;
			if(j>=i && x==1) k++;
		}
	fout<<k;
	return 0;
}