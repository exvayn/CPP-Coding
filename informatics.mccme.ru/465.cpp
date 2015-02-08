#include <fstream>
#include <vector>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,n,m,a,b;
	fin>>n>>m;
	std::vector < std::vector <int> > v(n, std::vector <int> (n));
	for (i=0;i<m;i++){ 
		fin>>a>>b;
		v[a-1][b-1]=1;
		v[b-1][a-1]=1;
	}
	for (i=0;i<n;i++){ 
		for (j=0;j<n;j++){
			fout<<v[i][j]<<" ";
		}
		fout<<"\n";
	}
	return 0;
}
