#include <iostream>
#include <vector>

using namespace std;

int dfs(vector <vector <int>> &v, vector <int> &u, int i, vector <int> &r){
	int j;
	u[i]=1;
	for (j=0;j<v[i].size();j++){
		if (!u[v[i][j]]) {
			dfs(v,u,v[i][j],r);
			r.push_back(v[i][j]);
		}
	}
	return 0;
}
int main(void){
	int m,n,i,j=0,a,b;
	cin>>n>>m;
	vector <vector <int>> v;
	vector <int> r;
	vector <int> u;
	while (n!=0){
		v.clear();
		v.resize(n);
		r.clear();
		u.clear();
		u.resize(n);
		for (i=0;i<m;i++){
			cin>>a>>b;
			v[a-1].push_back(b-1);
		}
		while (j==0){
			j=1;
			for (i=0;i<u.size();i++) if (u[i]==0){j=0; break;}
			if (j==0){
				dfs(v,u,i,r);
				r.push_back(i);
			}
		}
		for(i=r.size()-1;i>=0;i--)
			cout<<r[i]+1<<" ";
		cout<<endl;
		j=0;
		cin>>n>>m;
	}

	return 0;
}