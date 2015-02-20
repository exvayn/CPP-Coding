#include <iostream>
#include <vector>

using namespace std;


void dfs (vector <vector <int>> &v, vector<int> &u, int i) {
	u[i] = 1;
	for (int j=0; j<v[i].size(); j++)
		if (!u[j] && v[i][j]!=0){
			cout<<"in "<<j+1<<"\n";
			dfs (v,u,j);
			cout<<"out "<<j+1<<"\n";
		}
}

int main(void){

	int i,j,n; 
	cin>>n;// число вершин
	vector < vector<int> > v(n,vector<int>(n)) ; // граф
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>v[i][j];
	vector<int> u(n);
	cout<<"in 1\n";
	dfs(v, u, 0);
	cout<<"out 1\n";
	return 0;
}