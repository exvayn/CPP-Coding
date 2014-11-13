#include <fstream>
#include <vector>
#include <string>
void main(){
	int i,j,k=0,v=1,l;
	std::string s1,s2;
	std::vector <int> v1;
	std::vector <int> v2;
	std::vector <int> v3;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>s1>>s2;
	for (i=s1.length()-1;i>=0;i--) v1.push_back((int)(s1[i]-48));
	for (i=s2.length()-1;i>=0;i--) v2.push_back((int)(s2[i]-48));
	if(v1.size()<v2.size()){
		v=0;
	} else if(v1.size()==v2.size()){
		for (i=v1.size()-1;i>=0;i--)
			if(v1[i]>v2[i])	break; else
			if(v1[i]<v2[i]) {v=0; break;}
	}
	if (v){
		i=0;
		while(i<v1.size()){
			j=(i<v1.size() && i<v2.size())?v1[i]-v2[i]:v1[i];
			if (j<0) {
				for (l=i+1;l<v1.size();l++){
					if(v1[l]) {v1[l]=v1[l]-1; l=v1.size();}
					else {v1[l]=9;}
				}
				j=j+10;
			}
			v3.push_back(j);
			i++;
		}
	} else {
		fout<<'-';
			i=0;
		while(i<v2.size()){
			j=(i<v2.size() && i<v1.size())?v2[i]-v1[i]:v2[i];
			if (j<0) {
				for (l=i+1;l<v2.size();l++){
					if(v2[l]) {v2[l]=v2[l]-1; l=v2.size();}
					else {v2[l]=9;}
				}
				j=j+10;
			}
			v3.push_back(j);
			i++;
		}
	}
	for (i=v3.size()-1;i>=1;i--)
		if (!(v3[i])) {v3.pop_back();}
		else i=-1;
	for (i=v3.size()-1;i>=0;i--)
		fout<<v3[i];
}