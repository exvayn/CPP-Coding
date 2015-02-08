#include <fstream>
#include <vector>
using namespace std;
int main(void){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i,j,n,m,a,b;
	fin>>n>>m;
	vector <int> v(n);
	for (i=0;i<m;i++){
		fin>>a>>b;
		v[a-1]++;
		v[b-1]++;
	}
	a=v[0];
	for (i=1;i<n;i++) if (v[i]!=a) { fout<<"NO"; return 0;}
	fout<<"YES";
	return 0;
}

