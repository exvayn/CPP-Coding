#include <fstream>
void main(){
	int n,n1,k,s=0,s1,s2;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n>>k;
	n1=n;
	if (n1!=0){
		s1=1; s2=0;
		while (n1>=k){
			s1=s1*(n1%k);
			s2=s2+(n1%k);
			n1=n1/k;
		}
		s1=s1*(n1%k);
		s2=s2+(n1%k);
		s=s1-s2;
	}
		fout<<s;
}
/*
#include <fstream>
void main(){
	int n,n1,k,s=0,s1,s2,i,j,A[100];
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n>>k;
	n1=n;
	if (n1!=0){
		i=0;
		while (n1>=k){
			A[i]=n1%k;
			n1=n1/k;
			i++;
		}
		A[i++]=n1;
		s1=1; s2=0;
		for (j=0;j<i;j++){
			s1=s1*A[j];
			s2=s2+A[j];
		}
		s=s1-s2;
	}
		fout<<s;
}
*/