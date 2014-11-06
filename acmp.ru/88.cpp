#include <fstream>
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	int i,j,k,h,n,s,f,f1;
	s=1;
	int A[100][100];
	fin>>n;
	for (i=0;i<n*n;i++)               
		for (j=0;j<n*n;j++) {     
			fin>>A[i][j];
			if (A[i][j]>(n*n) || A[i][j]<1) s=0;
		}
	if (s){
		for (i=0;i<n*n;i++)               
			for (j=0;j<n*n;j++) {
				for (k=0;k<n*n;k++) 
					if(A[i][j]==A[k][j] && k!=i) {s=0; break;break;break;}
				for (k=0;k<n*n;k++) 
					if(A[i][j]==A[i][k] && k!=j) {s=0; break;break;break;}
			}
		if (s){
			f1=(n*n*(n*n+1))/2;
			for (i=0;i<n*n;i+=n)               
				for (j=0;j<n*n;j+=n) {
					f=0;
					for (k=i;k<i+n;k++) 
						for (h=j;h<j+n;h++)
							f=f+A[k][h];
					if (f!=f1) {s=0; break; break;}
				}
			}
	}
	(s)?fout<<"Correct":fout<<"Incorrect";
}