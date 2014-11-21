#include <fstream>
#include <cmath>
int fac(int n, int m);
void main(){
	int i,i1,n,m,s;
	float j;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n>>m;
	fout<<fac(n,n-m);
}
int fac(int n, int m){
	return((n && m)?fac(n-1,m)+fac(n-1,m-1):1);
}

/* grey code (ACCEPTED)
#include <fstream>
#include <cmath>
void main(){
	int i,i1,n,m,n2,q,k=0,s=0;
	float j;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n>>m;
	int*A=new int[n];
	for (i=0;i<n;i++) A[i]=0;
	if (k>=m) s++;
	n2=(int)(pow((float)2,(float)n));
	for (i=1;i<n2;i++){
		q=0; j=i;
		while(j/2==ceil(j/2)){
			j=j/2; q++;
		}
		A[q]=1-A[q];
		k=0;
		for (i1=0;i1<n;i1++) if (A[i1]) k++;
		if (k>=m) s++;
	}
	fout<<s;
}]
*/