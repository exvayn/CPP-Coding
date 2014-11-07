#include <fstream>
#include <cmath>
void main(){
	int s=1,k,i,A[10]={2, 3, 5, 7, 13, 17, 19, 31, 61, 89};
	//A - массив чисел n дл€ последовательности простых чисел ћерсенна (2^n-1)
	unsigned long long m,n;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>m>>n;
	k=1;
	//—овершенное число = 2^(n-1) * (2^n - 1), где n из массива A.
	for (i=0;i<10 && k;i++){
		if (n<pow((double)2,(double)(A[i]-1))*(pow((double)2,(double)A[i])-1)) k=0;
		else if (m<=pow((double)2,(double)(A[i]-1))*(pow((double)2,(double)A[i])-1)) {
			fout<<std::fixed<<((unsigned long long)(pow((double)2,(double)(A[i]-1))*(pow((double)2,(double)A[i])-1)))<<" ";
			s=0;
		}
	}
	if(s)fout<<"Absent";
}
/*
//HA-HA-HA, but it's working
#include <fstream>
void main(){
	int s=1;
	unsigned long long m,n;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>m>>n;
	if (m<=6 && n>=6)  {fout<<"6 "; s=0;}
	if (m<=28 && n>=28)  {fout<<"28 "; s=0;}
	if (m<=496 && n>=496)  {fout<<"496 "; s=0;}
	if (m<=8128 && n>=8128)  {fout<<"8128 "; s=0;}
	if (m<=33550336 && n>=33550336)  {fout<<"33550336 "; s=0;}
	if (m<=8589869056 && n>=8589869056)  {fout<<"8589869056 "; s=0;}
	if (m<=137438691328 && n>=137438691328)  {fout<<"137438691328 "; s=0;}
	if (m<=2305843008139952128 && n>=2305843008139952128)  {fout<<"2305843008139952128 "; s=0;}
	if(s)fout<<"Absent";
}


//TL 5 test
#include <fstream>
void main(){
	int n,i,j,m,s,s1=1;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>m>>n;
	for (i=m;i<=n;i++){
		s=0;
		for (j=1;j<=i/2;j++){
			if (!(i%j)) s+=j;
		}
		if (s==i) {fout<<s<<"\n"; s1=0;}
	}
	if(s1)fout<<"Absent";
}
*/