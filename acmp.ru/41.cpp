#include <stdio.h>
FILE *f;
void main(){
	int n,i,j,A[201],x;
	for (i=0;i<201;i++) A[i]=0;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);	
	for (i=0;i<n;i++) {fscanf(f,"%d",&x); A[x+100]++;} 
	fclose(f);
	f=fopen("output.txt","w");
	for (i=0;i<201;i++) 
		if (A[i]>0) 
			for (j=0;j<A[i];j++)
				fprintf(f,"%d ",i-100);
	fclose(f);
}