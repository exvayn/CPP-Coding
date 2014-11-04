#include <fstream>

void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	int i,j,n,m,s;
	int A[100][100],N=0,M=0;
	fin>>n>>m;
	for (i=0;i<n;i++)          //str     
		for (j=0;j<m;j++)      //stl
			fin>>A[i][j];
	for (i=0;i<m;i++){         //stl
		s=A[0][i];
		for (j=0;j<n;j++) if (s<A[j][i]) s=A[j][i];
		if (M>s || i==0) M=s;
	}
	for (i=0;i<n;i++){
		s=A[i][0];
		for (j=0;j<m;j++) if (s>A[i][j]) s=A[i][j];
		if (N<s || i==0) N=s;
	}
	fout<<N<<" "<<M;
}