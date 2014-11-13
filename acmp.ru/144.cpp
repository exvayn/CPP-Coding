#include <fstream>
#include <vector>
#include <string>
#include <cmath>
void main(){
	int i,j,k=0,s2;
	std::string s1;
	std::vector <int> v1;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>s1>>s2;
	for (i=s1.length()-1;i>=0;i--) v1.push_back((int)(s1[i]-48));
	for (i=0;i<v1.size();i++){
		v1[i] = v1[i]*s2+k;
		k = v1[i]/10;
		v1[i] = v1[i]%10;
	}
	while(k>0){
		v1.push_back(k%10);
		k= k/10;
	}
	for (i=v1.size()-1;i>0;i--) if(v1[i]==0) v1.pop_back(); else break;
	for (i=v1.size()-1;i>=0;i--) fout<<v1[i];
}