#include <fstream>
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	int A[100][100],h,i,j,t,w,k,t1;
	fin>>t;
	for (i=0;i<100;i++) for (j=0;j<100;j++) A[i][j]=0;
	for (t1=0;t1<t;t1++){
		k=0;
		fin>>w>>h;
		for (i=0;i<w;i++)
			for (j=0;j<h;j++)
				fin>>A[i][j];
		for (i=0;i<w-1;i++)
			for (j=0;j<h-1;j++)
				if (A[i][j]==A[i+1][j] && A[i][j+1]==A[i+1][j+1] && A[i][j+1]==A[i+1][j]) {k=1; break; break;}
		if (k==1) fout<<"NO\n"; else fout<<"YES\n";
		for (i=0;i<w;i++)
			for (j=0;j<h;j++)
				A[i][j]=0;
	}
}
