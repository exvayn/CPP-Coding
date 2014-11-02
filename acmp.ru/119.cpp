#include <stdio.h>
FILE *f;
void main(){
	int n,i,j,m,s,A[100][3];
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);	
	for (i=0;i<n;i++) fscanf(f,"%d %d %d",&A[i][0],&A[i][1],&A[i][2]); 
	fclose(f);
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++) {
			if ((A[i][0]>A[j][0]) || (A[i][0]==A[j][0] && (A[i][1]>A[j][1] || (A[i][1]==A[j][1] && A[i][2]>A[j][2])))) { 
				m=A[i][0]; A[i][0]=A[j][0]; A[j][0]=m;
				m=A[i][1]; A[i][1]=A[j][1]; A[j][1]=m;
				m=A[i][2]; A[i][2]=A[j][2]; A[j][2]=m;
			}
			if (A[i][0]==A[j][0] && A[i][1]>A[j][1]) { 
				m=A[i][0]; A[i][0]=A[j][0]; A[j][0]=m;
				m=A[i][1]; A[i][1]=A[j][1]; A[j][1]=m;
				m=A[i][2]; A[i][2]=A[j][2]; A[j][2]=m;
			}
		}
	f=fopen("output.txt","w");
	for (i=0;i<n;i++) fprintf(f,"%d %d %d\n",A[i][0],A[i][1],A[i][2]);
	fclose(f);
}