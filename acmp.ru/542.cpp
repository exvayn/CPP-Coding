#include <fstream>
#include <vector>
#include <cmath>
void main(){
	int i,n,s=0,j=0;
	std::vector <int> v;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	while (n>=2){
		v.push_back(n%2);
		n=n/2;
	}
	v.push_back(n%2);
	j=0;
	for (i=v.size()-1;i>=0;i--){
		s=s+v[i]*(int)pow((float)2,(float)j++);
	} 
	//std::copy(v.begin(),v.end(),std::ostream_iterator<int>(fout," "));
	fout<<s;
}