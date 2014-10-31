#include <stdio.h>
FILE *f;
void main(){
	int n,i,k,l,max,s,A[100];
	f=fopen("input.txt","r");
	fscanf(f,"%d",&n);	
	for (i=0;i<n;i++) fscanf(f,"%d",&A[i]); 
	fclose(f);
	s=l=k=0;
	do {
		max=A[k];
		for (i=k;i<n;i++) if(A[i]>max) { max=A[i]; k=i; }
		k++;
		s+=(k-l)*max;
		l=k;
	} while (k<n);
	f=fopen("output.txt","w");
	fprintf(f,"%d",s);
	fclose(f);
}