#include <fstream>
#include <vector>
using namespace std;

int dfs(vector <vector <int>> &v, vector <int> &u,int i){
	u[i]=1;
	for(int j=0;j<v[i].size();j++){
		if (!u[v[i][j]]) {
			dfs(v,u,v[i][j]);
		}
	}
	return 0;
}

int main(){
	int n,m,i,j,x;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>n>>m;
	vector <vector <int>> v(n);
	vector <int> u(n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			fin>>x;
			if (x){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	dfs(v,u,m-1);
	x=0;
	for(i=0;i<n;i++)
		if (u[i]) x++;
	fout<<x;
	return 0;
}
