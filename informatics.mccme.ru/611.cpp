#include <fstream>
#include <cmath>
using namespace std;

int main(){
	int x,y,h,m,k=0;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>x>>y;
	for (int i=x;i<=y;i++){
		h=0;
		m=sqrt((float) i);
		for (int j=2;j<=m;j++){
			if (i%j==0){h=1; break;}
		}
		if (h==0) {fout<<i<<endl; k=1;}
	}
	if (k==0) fout<<"Absent";
	return 0;
}