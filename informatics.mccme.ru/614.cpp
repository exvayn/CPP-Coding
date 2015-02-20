#include <fstream>
using namespace std;

int main(){
	int s1,s2,s3,x1,x2,x3,x4,y1,y2,y3,y4;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	s1=(x2-x1)*(y4-y1)-(x4-x1)*(y2-y1);
	s2=(x3-x2)*(y4-y2)-(x4-x2)*(y3-y2);
	s3=(x1-x3)*(y4-y3)-(x4-x3)*(y1-y3);
	if ((s1>=0 && s2>=0 && s3>=0) || (s1<=0 && s2<=0 && s3<=0))
		fout<<"In";
	else
		fout<<"Out";
	return 0;
}
