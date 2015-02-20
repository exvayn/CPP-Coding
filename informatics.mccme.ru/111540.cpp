#include <fstream>
#include <vector>
using namespace std;

int dfs(vector <vector <int>> &v, vector <int> &u, vector <vector <int>> &r,int i){
	u[i]=1;
	r[r.size()-1].push_back(i);
	for(int j=0;j<v[i].size();j++){
		if (!u[v[i][j]]) {
			dfs(v,u,r,v[i][j]);
		}
	}
	return 0;
}

int main(){
	int n,m,i,j,a,b;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>n>>m;
	vector <vector <int>> v(n);
	vector <vector <int>> r;
	vector <int> u(n);
	for(i=0;i<m;i++){
			fin>>a>>b;
				v[a-1].push_back(b-1);
				v[b-1].push_back(a-1);
		}

	for(i=0;i<n;i++) if (!u[i]) {
		r.push_back(vector <int> ());
		dfs(v,u,r,i);
	}
	
	fout<<r.size()<<endl;
	for(i=0;i<r.size();i++){
		fout<<r[i].size()<<endl;
		for(j=0;j<r[i].size();j++)
			fout<<r[i][j]+1<<" ";
		fout<<endl;
	}

	return 0;
}
