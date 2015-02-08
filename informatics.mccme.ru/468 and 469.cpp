#include <fstream>
#include <vector>
using namespace std;
int main(void){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i,j,n,m,a,b;
	fin>>n>>m;
	std::vector < std::vector <int> > v(n, std::vector <int> (n));
	for (i=0;i<m;i++){ 
		fin>>a>>b;
			if (v[a-1][b-1]==1) {fout<<"YES";return 0;} else v[a-1][b-1]++;
	}
	fout<<"NO";
	return 0;
}

