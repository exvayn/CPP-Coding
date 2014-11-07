#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
void main(){
	int i,n,n1,s1,j,k;
	char v[1000]="";
	std::vector <int> s;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	for (i=2;i<=36;i++){
	itoa(n,v,i);
	k=1;
	for (j=0;j<strlen(v)/2;j++)
		if (v[j]!=v[strlen(v)-1-j]) {k=0; break;}
		if (k) {s.push_back(i);}
		v[0]='\0';
	}
	(s.size())?(s.size()>1)?fout<<"multiple\n":fout<<"unique\n":fout<<"none\n";
	std::copy(s.begin(),s.end(),std::ostream_iterator<int>(fout," "));
}

/*
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
void main(){
	int i,n,n1,s1,j,k;
	std::vector <char> v;
	std::vector <int> s;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	for (i=2;i<=36;i++){
		n1=n;
		while (n1>=i){
			(n1%i>9)?v.push_back(n1%i-10+'A'):v.push_back(n1%i+'0');
			n1=n1/i;
		}
	(n1%i>9)?v.push_back(n1%i-10+'A'):v.push_back(n1%i+'0');
	//std::copy(v.begin(),v.end(),std::ostream_iterator<char>(fout,""));
	k=1;
	for (j=0;j<v.size()/2;j++)
		if (v[j]!=v[v.size()-1-j]) {k=0; break;}
		if (k) {s.push_back(i);}
	v.clear();
	}
	(s.size())?(s.size()>1)?fout<<"multiple\n":fout<<"unique\n":fout<<"none\n";
	std::copy(s.begin(),s.end(),std::ostream_iterator<int>(fout," "));
}
*/