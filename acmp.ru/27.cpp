#include <fstream>
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	int A[100][100],i,j,w,h,n,x1,y1,x2,y2,s,k;
	fin>>w>>h>>n;
	for (i=0;i<w;i++)
		for (j=0;j<h;j++) A[i][j]=0;
	for (k=0;k<n;k++) {
		fin>>x1>>y1>>x2>>y2;
		for (i=x1;i<x2;i++)
			for (j=y1;j<y2;j++)
				A[i][j]=1;
	} 
	s=0;
	for (i=0;i<w;i++)
		for (j=0;j<h;j++)
			if (A[i][j]==0) s++;
	fout<<s;
}
