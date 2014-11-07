#include <fstream>
#include <vector>
#include <cmath>
void main(){
	int i,n,s=0,s1,j,j1,j2;
	std::vector <int> v;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	while (n>=2){
		v.push_back(n%2);
		n=n/2;
	}
	v.push_back(n%2);
	//std::copy(v.begin(),v.end(),std::ostream_iterator<int>(fout," "));
	j=0;
	for (i=0;i<v.size();i++){
		s1=0; j2=v.size()-1;
		for (j=v.size()-1-i;j>=0-i;j--){
			j1=(j<0)?v.size()+j:j; 
			s1=s1+v[j1]*(int)pow((float)2,(float)j2--);
			if (s<s1)s=s1;
		}
	} 
	fout<<s;
}