#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main(void){
	int i,j,n;
	cin>>n;
	vector < vector <int> > v(n);
	string line;
	getline(cin, line);
	for (i=1;i<=n;i++){
		getline(cin, line);
		istringstream sin(line);
		while (sin >> j){
			v[j-1].push_back(i);
		}
	}
	cout<<n;
	for (i=0;i<n;i++){
		cout<<"\n";
		for (j=0;j<v[i].size();j++)
			cout<<v[i][j]<<" ";
	}
	system("pause");
	return 0;
}