#include <fstream>
#include <string>
void main(){
	int i,b=1,m;
	std::string s;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	std::getline (fin,s);
	m=2;
	for (i=0;i<s.length();i++)
		if(((int)s[i])<48 || ((int)s[i])>57 && ((int)s[i])<65 || ((int)s[i])>90){
			b=0; break;
		} else {
			if (((int)s[i])>=48 && ((int)s[i])<=57){
				if  (m<((int)s[i])-47) m=((int)s[i])-47;
			} else {
				if  (m<((int)s[i])-54) m=((int)s[i])-54;
			}
		}
	if (b) fout<<m; else fout<<"-1";
}