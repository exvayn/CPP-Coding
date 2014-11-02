#include <stdio.h>
FILE *f;
void main(){
    int i,j,d,k=0,A[100000],s=1,h;
    f=fopen("input.txt","r");
	while (fscanf(f,"%d",&A[k])!=EOF) k++;
    fclose(f);
   
	for (i=0;i<k;i++){
        for (j=i+1;j<k;j++)
            if (A[i]>A[j]) {d=A[i]; A[i]=A[j]; A[j]=d;}
			if (i==1) h=A[i]-A[i-1];
			else if (i>1 && A[i]!=A[0]+i*h) {s=0; break;}
	}
    f=fopen("output.txt","w");
	fprintf(f,"%s",(s==1)?"Yes":"No");
    fclose(f);
}