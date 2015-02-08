#include <fstream>
#include <vector>
int main(void){
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	int i,j,k,n,min;
	fin>>n;
	std::vector < std::vector <int> > v(n, std::vector <int>(n));
	std::vector <int> c(3);
	//matrix
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++){
			fin>>v[i][j];
		}
	//search
	min=100000000;
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			for (k=j+1;k<n;k++)
				if (v[i][j]+v[j][k]+v[k][i]<min){
					c[0]=i; c[1]=j; c[2]=k;
					min=v[i][j]+v[j][k]+v[k][i];
				}
	fout<<c[0]+1<<" "<<c[1]+1<<" "<<c[2]+1;
	return 0;
}