#include <fstream>
#include <string>
#include <vector>	
#include <algorithm>
std::string B[1000];
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	int n,i,j; 
	std::string k1;
	double p,m; //m-единица измерения p-приставка
	fin>>n;
	std::vector <int> A(n);
	std::vector <double> A1(n);
	std::vector <double> A2(n);
	for (i=0;i<n;i++) {
		p=1;m=1;
		fin>>A[i];    fin>>B[i];
		if (B[i].length()==2){
			switch (B[i][0]){
				case 'm': {p=0.001; break;}
				case 'k': {p=1000; break;}
				case 'M': {p=1000000; break;}
				case 'G': {p=1000000000; break;}
			}
		}
		switch (B[i][B[i].length()-1]){
			case 'g':{ m=1;break;}
			case 'p':{ m=16380;break;}
			case 't':{ m=1000000;break;}
		}
		A1[i]=A[i]*p*m;
		A2[i]=A1[i];
	}
	std::stable_sort(A1.begin(), A1.end());
	for (i=0;i<n;i++)
		for (j=0;j<n;j++){
			if (A1[i]==A2[j]) {fout<<A[j]<<" "<<B[j]<<"\n"; A2[j]=0; break;}
		}
}



/*
#include <fstream>
#include <string>
#include <vector>	

std::vector <int> A(1000);
std::vector <long double> A1(1000);
std::string B[1000];
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	int n,i,j,k,o,l; 
	std::string k1;
	long double p,m,s; //m-единица измерения p-приставка
	fin>>n;
	for (i=0;i<n;i++) {
		p=1;m=1;
		fin>>A[i];    fin>>B[i];
		if (B[i].length()==2){
			switch (B[i][0]){
				case 'm': {p=0.001; break;}
				case 'k': {p=1000; break;}
				case 'M': {p=1000000; break;}
				case 'G': {p=1000000000; break;}
			}
		}
		switch (B[i][B[i].length()-1]){
			case 'g':{ m=1;break;}
			case 'p':{ m=16380;break;}
			case 't':{ m=1000000;break;}
		}
		A1[i]=A[i]*p*m;
		//fout<<std::fixed<<A1[i]<<" "<<p<<" "<<m<<"\n"<<std::endl;
	}
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++){
			//fout<<i<<""<<j<<" - "<<A1[i]<<"--"<<A1[j]<<"\n";
			if (A1[i]>A1[j]) {
				k=A[j]; k1=B[j]; o=A1[j];
				for (l=j;l>i;l--) {A1[l]=A1[l-1]; A[l]=A[l-1]; B[l]=B[l-1];}
				A[i]=k; B[i]=k1; A1[i]=o;
				//for (i=0;i<n;i++) fout<<A[i]<<" "<<B[i]<<"\n";
				//fout<<"\n";
			}
		
		}
		//fout<<"\n";
	for (i=0;i<n;i++) fout<<A[i]<<" "<<B[i]<<"\n";
}

*/