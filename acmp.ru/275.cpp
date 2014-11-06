#include <fstream>
#include <string>
#include <stdlib.h>
void main(){
	int i,k,n,j,l,s;
	std::string c;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	for(k=1;k<=n;k++){
		s=j=0;
		fin>>c;
		i=c.length();
		if (i%3!=0){
			if ((i+1)%3==0) {c="0"+c; i++;}
			else {c="00"+c; i+=2;}
		}
		i--;
		while (i>=0){
			l=3;
			s+=(c.substr(i-2,l)=="001")?1:
				(c.substr(i-2,l)=="010")?2:
				(c.substr(i-2,l)=="011")?3:
				(c.substr(i-2,l)=="100")?4:
				(c.substr(i-2,l)=="101")?5:
				(c.substr(i-2,l)=="110")?6:7;
			i=i-3;
		}
		(s%7==0)?fout<<"Yes\n":fout<<"No\n";
	}
}