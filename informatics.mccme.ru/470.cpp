#include <fstream>
#include <vector>
using namespace std;
int main(void){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int i,j,n,x;
	fin>>n;
	vector <int> v(n);
	for (i=0;i<n;i++)
		for (j=0;j<n;j++){ 
			fin>>x;
			if (x==1) v[i]++;
		}
	for (i=0;i<n;i++) fout<<v[i]<<endl;
	return 0;
}