#include <fstream>
#include <vector>
using namespace std;
int main(void){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i,j,n,m,a,b;
	fin>>n>>m;
	vector < pair<int,int> > v(n);
	for (i=0;i<m;i++){
		fin>>a>>b;
		v[a-1].second++;
		v[b-1].first++;
	}
	for (i=0;i<n;i++) fout<<v[i].first<<endl<<v[i].second<<endl;
	return 0;
}