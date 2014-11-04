#include <fstream>
int A[750][750],N[750],M[750];
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	int i,j,n,m,s;
	fin>>n>>m;
	for (i=0;i<n;i++)          //str     
		for (j=0;j<m;j++)      //stl
			fin>>A[i][j];
	for (i=0;i<m;i++){         //stl
		s=A[0][i];
		for (j=0;j<n;j++) if (s<A[j][i]) s=A[j][i];
		M[i]=s;
	}
	for (i=0;i<n;i++){
		s=A[i][0];
		for (j=0;j<m;j++) if (s>A[i][j]) s=A[i][j];
		N[i]=s;
	}
	s=0;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (A[i][j]==N[i] && A[i][j]==M[j]) s++;
	fout<<s;
}
