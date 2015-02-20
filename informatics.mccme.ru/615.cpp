#include <fstream>
#include <vector>
using namespace std;

int main(){
	int a,n,b,i,j;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>a>>n;
	b=a;
	vector<int> v;
	while(a){
		v.push_back(a);
		v[v.size()-1]%=10;
		a/=10;
	}
	a=0;
	for (i=1;i<n;i++){
		for (j=0;j<v.size();j++){
			v[j]=v[j]*b+a;
			a=v[j]/10;
			v[j]%=10;
		}
		while(a){
			v.push_back(a);
			v[j++]%=10;
			a/=10;
		} 
	}
	for (i=v.size()-1;i>=0;i--)
		fout<<v[i];
	return 0;
}
