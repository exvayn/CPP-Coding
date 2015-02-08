#include <fstream>
#include <vector>
using namespace std;
int main(void){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i,j,n,x,o=0,p=0;
	fin>>n;
	vector < pair<int,int> > v(n);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++){ 
			fin>>x;
			if (x==1) {
				v[i].second++;
				v[j].first++;
			}
		}
	for (i=0;i<n;i++) {
		if(v[i].first==0) o++;
		if(v[i].second==0) p++;
		}
	fout<<o<<" ";
	for (i=0;i<n;i++) {
		if(v[i].first==0) fout<<i+1<<" ";
		}
		fout<<endl;
	fout<<p<<" ";
	for (i=0;i<n;i++) {
		if(v[i].second==0) fout<<i+1<<" ";
		}
	return 0;
}
