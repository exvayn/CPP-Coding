#include <fstream>
#include <vector>
#include <cmath>
void main(){
	int n,i,j,k,s=0;
	std::vector <int> v;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	v.push_back(2);
	if (2>n) s=1;
	for (i=3;i<2*n;i+=2){
		k=1;
		j=0;
		while(v[j]<=sqrt((float)i) && j<v.size()){
			if (!(i%v[j])) {k=0; break;}
			j++;
		}
		if (k) {
			v.push_back(i);
			if (i>n) s++;
		}
	}
	fout<<s;
}