#include <fstream>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,n,x;
	fin>>n;
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++){
			fin>>x;
			if (x==1) fout<<i+1<<" "<<j+1<<std::endl;
		}
	return 0;
}

