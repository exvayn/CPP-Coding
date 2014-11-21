#include <fstream>
int A[200][200];
int B[200][200];
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	int x,k,y,i,j,h,g,f=0;
	fin>>x>>k;
	y=x/5;
		A[0][1]=1; A[0][0]=1;
		B[0][1]=1; B[0][0]=1;
	for (i=1;i<=y+k;i++){
		if (i%2) 
			for (j=1;j<=i;j++){
				    h=1;
					while(h<=((A[j-1][0]>A[j][0])?A[j-1][0]:A[j][0]) || f!=0){
						g=(h<=A[j-1][0] && h<=A[j][0])?A[j-1][h]+A[j][h]+f:(h>A[j-1][0] && h>A[j][0])?f:(h<=A[j-1][0] && h>A[j][0])?f+A[j-1][h]:f+A[j][h];
						(g>9)?f=g/10,g%=10:f=0;
						B[j][h]=g;
						h++;
						B[j][0];
					}
					B[j][0]=--h;
			}
		else for (j=1;j<=i;j++){
				    h=1;
					while(h<=((B[j][0]>B[j-1][0])?B[j][0]:B[j-1][0]) || f!=0){
						g=(h<=B[j][0] && h<=B[j-1][0])?B[j][h]+B[j-1][h]+f:(h>B[j][0] && h>B[j-1][0])?f:(h<=B[j][0] && h>B[j-1][0])?f+B[j][h]:f+B[j-1][h];
						(g>9)?f=g/10,g%=10:f=0;
						A[j][h]=g;
						h++;
						A[j][0];
					}
					A[j][0]=--h;
			}
		B[j][0];A[j][0];
	}
	if ((y+k)%2){
		for (i=B[k][0];i>0;i--)
			fout<<B[k][i];
	}else{
		for (i=A[k][0];i>0;i--)
			fout<<A[k][i];
	}
}

/* runtime error
#include <fstream>
#include <vector>
std::vector<int> fact(int x, int y);
void main(){
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	int x,k,y,i;
	fin>>x>>k;
	y=x/5;
	std::vector<int> v = fact(y+k,y);
	for (i=v.size()-1;i>=0;i--)
		fout<<v[i];
}
std::vector<int> fact(int x, int y)
{
	int i,j,k=0;
	std::vector<int> v;
	if(x==y) {
		v.push_back(1);
		return v;
	}
    if(y==1) {
		v.push_back(x);
		return v;
	}
	std::vector<int> v1=fact(x-1, y-1);
	std::vector<int> v2=fact(x-1, y);
    i=0;
	while(i<((v1.size()>v2.size())?v1.size():v2.size()) || k!=0){
		j=(i<v1.size() && i<v2.size())?v1[i]+v2[i]+k:(i>=v1.size() && i>=v2.size())?k:(i<v1.size() && i>=v2.size())?k+v1[i]:k+v2[i];
		(j>9)?k=j/10,j%=10:k=0;
		v.push_back(j);
		i++;
	}
    return v;
}
*/