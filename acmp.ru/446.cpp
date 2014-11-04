#include <fstream>
#include <string>
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	std::string S;
	int i,j,n,m;
	int A[100][100],N=0,M=0;
	char B[100][100];
	fin>>n>>m;
	for (i=0;i<n;i++)               
		for (j=0;j<m;j++)      
			fin>>B[i][j];
	for (i=0;i<n;i++)               
		for (j=0;j<m;j++)      
			fin>>A[i][j];
	S="YES";
	for (i=0;i<n;i++)               
		for (j=0;j<m;j++) 
			switch (B[i][j]){
				case 'R':{ if(A[i][j]<4) {S="NO"; break; break; break;} else break;}
				case 'G':{ if(A[i][j]<2 || (A[i][j]>3 && A[i][j]<6)) {S="NO"; break; break; break;} else  break;}
				case 'B':{ if(A[i][j]==0 || A[i][j]==2 || A[i][j]==4 || A[i][j]==6) {S="NO"; break; break; break;} else  break;}
			}

		fout<<S;
}