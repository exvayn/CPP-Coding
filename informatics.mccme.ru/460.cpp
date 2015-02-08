#include <fstream>
#include <vector>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,n;
	fin>>n;
	std::vector < std::vector <int> > v(n, std::vector <int>(n));
	//matrix
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++){
			fin>>v[i][j];
		}
	//проверка
	for (i=0;i<n;i++) 
		for (j=i;j<n;j++)
			if(i==j){ if(v[i][j]!=0){ fout<<"NO"; return 0;}}else 
			if(v[i][j]!=v[j][i]) { fout<<"NO"; return 0;}
	fout<<"YES";
	return 0;
}
