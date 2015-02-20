#include <iostream>
#include <vector>

using namespace std;

void dfs (vector<vector<int>> &v, vector<int> &u, vector<int> &tin, vector<int> &fup,int &timer,int i, int p = -1) {
	u[i] = 1;
	tin[i] = fup[i] = timer++;
	for (size_t j=0; j<v[i].size(); j++) {
		int to = v[i][j];
		if (to == p)  continue;
		if (u[to])
			fup[i] = min (fup[i], tin[to]);
		else {
			dfs (v, u, tin, fup,timer,to,i);
			fup[i] = min(fup[i], fup[to]);
			if (fup[to] > tin[i])
				cout<<i+1<<"  "<<to+1<<endl;
		}
	}
}

int main(void){
	int n,m,a,b,timer=0;
	cin>>n>>m;
	vector<vector<int>> v(n);
	vector<int> u(n), tin(n), fup(n);
	for(int i=0;i<m;i++){
		cin>>a>>b;
		v[a-1].push_back(b-1);
	}
	for (int i=0; i<u.size(); ++i)
		if (!u[i])
			dfs (v, u, tin, fup,timer,i);

	return 0;
}