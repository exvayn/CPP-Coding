#include <stdio.h>
FILE *f;
void main(){
	int n,i,A[1000];
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);
	for (i=0;i<n;i++) fscanf(f,"%d",&A[i]);
	fclose(f);
	
	f=fopen("output.txt","w");
	for (i=n-1;i>=0;i--) fprintf(f,"%d ",A[i]);
	fclose(f);
}