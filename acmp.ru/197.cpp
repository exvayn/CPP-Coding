#include <fstream>
void main(){
	int n,A[100][100],i,j,p,k,s=1;
	std::ifstream fin; fin.open("input.txt");
	std::ofstream fout; fout.open("output.txt");
	fin>>n;
	p=n+n-1;
	for (k=1;k<=p;k++) {
		if (k%2==0){
			for (i=0;i<n;i++)
				for (j=0;j<n;j++)
					if(i+j+1==k) A[j][i]=s++;
					
		} else {
			for (i=0;i<n;i++)
				for (j=0;j<n;j++)
					if(i+j+1==k) A[i][j]=s++;
		}
	}
	for (i=0;i<n;i++){
		for (j=0;j<n;j++)
			fout<<A[i][j]<<" ";
		fout<<"\n";
	}

}