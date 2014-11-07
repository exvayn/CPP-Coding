#include <fstream>  
#include <vector>
void main(){
	int i,n,n1;
	std::vector <int> v;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	n1=n;
	while (n1>3) {
		(n1%3)?v.push_back(n1%3):v.push_back(3);
		n1=(n1%3)?n1/3:(n1/3)-1;
	}
	(n1%3)?v.push_back(n1%3):v.push_back(3);
	for (i=v.size()-1;i>=0;i--)
		fout<<v[i];
}