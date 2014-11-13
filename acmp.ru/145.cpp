#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,b,k=1,c=0,s2,x=0;
	std::string s1;
	std::vector <int> v1;
	std::vector <int> v2;
	std::vector <int> v3;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>s1>>s2;
	for (i=s1.length()-1;i>=0;i--) v1.push_back((int)(s1[i]-48));
	for (i=v1.size()-1;i>=0;i--){
		x = x*10+v1[i];
		if(x < s2 && k && i > 0) continue;
		k=0;
		v3.push_back(x/s2);
		x%=s2;
	}
	std::copy(v3.begin(),v3.end(),std::ostream_iterator<int>(fout,""));
}