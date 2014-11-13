#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,b,k,c=0;
	std::string s1,s2;
	std::vector <int> v1;
	std::vector <int> v2;
	std::vector <int> v3;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>s1>>s2;
	v3.push_back(0);
	for (i=s1.length()-1;i>=0;i--) v1.push_back((int)(s1[i]-48));
	for (i=s2.length()-1;i>=0;i--) v2.push_back((int)(s2[i]-48));

	for (i=0;i<v2.size();i++){
		for (j=0;j<v1.size();j++){
			k=i+j;
			c=v2[i]*v1[j];
			do{
				if (k>v3.size()-1) v3.push_back(0);
				v3[k]+=c%10;
				c/=10;
				if (v3[k]>9) {c+=v3[k]/10; v3[k]%=10;}
				k++;
			}while(c);
		}
	}
	for (i=v3.size()-1;i>=1;i--)
	if (!(v3[i])) v3.pop_back(); else i=-1;
	for (i=v3.size()-1;i>=0;i--) fout<<v3[i];
}