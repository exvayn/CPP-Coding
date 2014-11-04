#include <fstream>
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	char A[102][102];
	int i,j,n,m,s;
	fin>>n>>m;
	for (i=0;i<=n+1;i++)
		for (j=0;j<=m+1;j++)
			A[i][j]='.';

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++){
			fin>>A[i][j];
		}
	s=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (A[i][j]=='.' && A[i-1][j]=='.' && A[i][j-1]=='.' && A[i+1][j]=='.' && A[i][j+1]=='.')
				s++;
	fout<<s;
}
