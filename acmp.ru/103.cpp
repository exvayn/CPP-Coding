#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,k=0;
	std::string s1,s2;
	std::vector <int> v1;
	std::vector <int> v2;
	std::vector <int> v3;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>s1>>s2;
	for (i=s1.length()-1;i>=0;i--) v1.push_back((int)(s1[i]-48));
	for (i=s2.length()-1;i>=0;i--) v2.push_back((int)(s2[i]-48));
	i=0;
	while(i<((v1.size()>v2.size())?v1.size():v2.size()) || k!=0){
		j=(i<v1.size() && i<v2.size())?v1[i]+v2[i]+k:(i>=v1.size() && i>=v2.size())?k:(i<v1.size() && i>=v2.size())?k+v1[i]:k+v2[i];
		(j>9)?k=j/10,j%=10:k=0;
		v3.push_back(j);
		i++;
	}
	for (i=v3.size()-1;i>=0;i--)
		fout<<v3[i];
	//std::copy(v2.begin(),v2.end(),std::ostream_iterator<int>(fout," "));

}