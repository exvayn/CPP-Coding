#include <fstream>
#include <vector>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,k=0,n;//k-bridges
	fin>>n;
	std::vector < std::vector <int> > v(n, std::vector <int>(n));
	std::vector <int> c(n);
	//matrix
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++){
			fin>>v[i][j];
		}
	//color
	for (i=0;i<n;i++){
		fin>>c[i];
	}
	for (i=0;i<n;i++) 
		for (j=i+1;j<n;j++){
			if(v[i][j]==1 && c[i]!=c[j]) k++;
		}
	fout<<k;
	//std::copy(v.begin(),v.end(),std::ostream_iterator<int>(fout," "));
	return 0;
}
