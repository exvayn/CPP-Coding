#include <fstream>
#include <vector>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,k,n,x;
	fin>>n>>k;
	std::vector <int> v(n);
	for (i=0;i<k*2;i++){
		fin>>x;
		v[x-1]++;
	}
	for (i=0;i<n;i++){
		fout<<v[i]<<" ";
	}
	return 0;
}


