#include <stdio.h>
FILE *f;
void main(){
	int n,i,j,m,A[40];
	double k;
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);	
	for (i=0;i<n;i++) fscanf(f,"%d",&A[i]); 
	fscanf(f,"%lf",&k);
	fclose(f);
	for (i=0;i<n;i++){
		for (j=i+1;j<n;j++)
			if (A[i]>A[j]) {m=A[i]; A[i]=A[j]; A[j]=m;}
	}
	for (i=0;i<n;i++) if (k<A[i]) k=(k+A[i])/2;
	f=fopen("output.txt","w");
	fprintf(f,"%.6lf\n",k);
	fclose(f);
}