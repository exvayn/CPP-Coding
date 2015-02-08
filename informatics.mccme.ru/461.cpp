#include <fstream>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,n,x;
	fin>>n;
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++){
			fin>>x;
			if (i==j && x==1) { fout<<"YES"; return 0; }
		}
	fout<<"NO";
	return 0;
}