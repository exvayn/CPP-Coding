#include <fstream>
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	char A[202][202];
	int i,j,n,m,k,k1,x,y;
	fin>>n>>m>>k;
	for (i=0;i<=n+1;i++)
			for (j=0;j<=m+1;j++)
				A[i][j]='0';
	for (k1=0;k1<k;k1++){
		fin>>x>>y;
		for (i=x-1;i<=x+1;i++)
			for (j=y-1;j<=y+1;j++)
				if(A[i][j]!='*') A[i][j]=((A[i][j]-'0')+1)+'0';
		A[x][y]='*';
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
			if (A[i][j]=='0') A[i][j]='.'; 
	for (i=1;i<=n;i++){
		for (j=1;j<=m;j++) fout<<A[i][j];
		fout<<"\n";
	}
}
