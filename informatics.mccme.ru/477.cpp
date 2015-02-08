#include <fstream>
#include <vector>
using namespace std;
int main(void){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i,j,n,m,a,b;
	fin>>n>>m;
	vector < std::vector <int> > v(n, vector <int> (n));
	for (i=0;i<m;i++){
		fin>>a>>b;
		v[a-1][b-1]=1;
		v[b-1][a-1]=1;
	}
	for (i=0;i<n;i++) 
		for (j=0;j<n;j++) 
			if (v[i][j]==0 && i!=j) { fout<<"NO"; return 0;}
	fout<<"YES";
	return 0;
}