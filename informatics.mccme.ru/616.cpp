#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int i,s=1,k=0,o1=0,o2=0,ogo=0;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	vector <int> v(5);
	for(i=0;i<5;i++) fin>>v[i];
	sort(v.begin(),v.end());
	for (i=1;i<5;i++){
		if (s && v[i]-v[i-1]!=1) s=0;
		if (v[i]==v[i-1]) {
			if (i==1) {ogo=v[i]; o1++;}
			else if (!ogo && i==2){ogo=v[i]; o1++;}
			else (v[i]==ogo)?o1++:o2++;
		}
	}
	switch(o1){
		case 0:{
			if (o2>0){
				switch(o2){
					case 1: {fout<<"One Pair"; break;}
					case 2: {fout<<"Three of a Kind"; break;}
					case 3: {fout<<"Four of a Kind"; break;}
				}
			} else if (s) fout<<"Straight";
			else fout<<"Nothing";
			break;
		}
		case 1:{
			switch(o2){
				case 1: {fout<<"Two Pairs"; break;}
				case 2: {fout<<"Full House"; break;}
				default:{fout<<"One Pair"; break;}
			}
			break;
		}
		case 2:{
			switch(o2){
				case 1: {fout<<"Full House"; break;}
				default:{fout<<"Three of a Kind"; break;}
			}
			break;
		}
		case 3: {fout<<"Four of a Kind"; break;}
		case 4: {fout<<"Impossible"; break;}
	}
	return 0;
}

