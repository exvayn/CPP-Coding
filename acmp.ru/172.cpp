#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,s2;
	std::string s1;
	std::vector <int> v1;
	long long x=0;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>s1>>s2;
	for (i=s1.length()-1;i>=0;i--) v1.push_back((int)(s1[i]-48));
	for (i=v1.size()-1;i>=0;i--){
		x = x*10+v1[i];
		if(x < s2) continue;
		x%=s2;
	}
	fout<<x;
}