#include <fstream>
#include <vector>
#include <cmath>
void main(){
	int n,m,i,j,k,l=1;
	std::vector <int> v;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>m>>n;
	v.push_back(2);
	if (2>=m) {fout<<2<<" ";l=0;}
	for (i=3;i<=n;i+=2){
		k=1;
		j=0;
		while(v[j]<=sqrt((float)i) && j<v.size()){
			if (!(i%v[j])) {k=0; break;}
			j++;
		}
		if (k) {
			v.push_back(i);
			if (i>=m) {fout<<i<<" ";l=0;}
		}
	}
	if (l) fout<<"Absent";
}