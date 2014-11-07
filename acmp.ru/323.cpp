#include <fstream>
#include <cmath>
int just(int n);
void main(){
	int n,i;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	for (i=2;i<=n/2;i++){
		if (just(i) && just(n-i)){
			fout<<i<<" "<<(n-i);
			break;
		}
	}
}
int just(int n){
	int i;
	for (i=2;i<=sqrt((float)n);i++)
		if (!(n%i)) return 0;
	return 1;
}