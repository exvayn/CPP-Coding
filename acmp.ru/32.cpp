#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>	
#include <algorithm>

void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt"); 
	std::string S[2];
	int i,j,k;
	fin>>S[0];   fin>>S[1];
	int l1=S[0].length(),l2=S[1].length();
	std::vector <int> A(l1);
	std::vector <int> B(l2);
	for (i=l1-1;i>=0;i--) A[i]=((int)S[0][i])-48; 
	for (i=l2-1;i>=0;i--) B[i]=((int)S[1][i])-48;
	
	stable_sort(A.begin(), A.end());
	stable_sort(B.begin(), B.end());
	if (S[0][0]=='-') {
		k=1;
		for (i=1;i<l1;i++) {
			if (k==1 && A[i]!=0) {if (i!=1) {S[0][1]=A[i]+48; S[0][i]='0';} else S[0][i]=A[i]+48; k=0;}
			else S[0][i]=A[i]+48;
		}
	} else {
		k=0;
		for (i=l1-1;i>=0;i--) {S[0][k]=A[i]+48; k++;}
	}
	if (S[1][0]=='-') {
		k=1;
		for (i=l2-1;i>0;i--) {S[1][k]=B[i]+48; k++;}
	} else {
		k=1;  j=0;
		for (i=0;i<l2;i++) {
			if (k==1 && B[i]!=0) {if (i!=0) {S[1][0]=B[i]+48; S[1][i]='0';} else {S[1][i]=B[i]+48; j++;} k=0;}
			else {S[1][j]=B[i]+48; j++;}
		}
		for (i=j;i<l2;i++) S[1][j]='0';
	}
	
	fout<<atoi(S[0].c_str())-atoi(S[1].c_str());
}
