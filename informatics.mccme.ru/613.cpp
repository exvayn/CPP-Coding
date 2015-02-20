#include <fstream>
#include <vector>
using namespace std;

int main(){
	int n,i,j,max_i,max,total_max=1,total_max_i=0;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>n;
	vector <int> v(n);
	vector <pair<int,int>> k(n);
	for (i=0;i<n;i++){
		fin>>v[i];
		max_i=i; max=0;
		for(j=i-1;j>=0;j--){
			if(v[i]>v[j] && k[j].first>max) {
				max=k[j].first;
				max_i=j;
			}
		}
		k[i].first=++max;
		k[i].second=max_i;
		if(max>total_max) {total_max=max; total_max_i=i;}
	}
	fout<<total_max<<endl;
	vector <int> v1(total_max);
	i=total_max_i;
	j=0;
	do{
		v1[v1.size()-1-(j++)]=v[i];
		i=k[i].second;
	}while(i!=k[i].second);
	v1[0]=v[i];
	for (i=0;i<v1.size();i++)
		fout<<v1[i]<<" ";
	return 0;
}

