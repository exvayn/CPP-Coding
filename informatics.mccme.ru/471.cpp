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
	for (i=0;i<n;i++) fout<<v[i]<<endl;
	return 0;
}
