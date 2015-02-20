#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

void quick_sort(vector<int> &v, int b0, int e0){
	int d=v[e0];
	int b=b0;
	int e=e0;
	do{
		while(v[b]< d)
			b++;
		while(v[e]>d)
			e++;
		if (b<=e){
			swap(v[b],v[e]);
			b++;
			e++;
		}
	} while(b<=e);
	if (e>b0)
		quick_sort(v,b0,e);
	if (b<e0)
		quick_sort(v,b,e0);
}
int main(){
	vector <int> v;
	for (int i=0; i<20; ++i)
		v.push_back(i);
	for (int i=0; i<v.size(); ++i)
		swap(v[i],v[rand()%(v.size()-i)+i]);
	for (int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
	quick_sort(v,0,v.size()-1);
	for (int i=0; i<v.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;
}