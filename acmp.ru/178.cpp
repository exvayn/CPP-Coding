#include <stdio.h>
int A[200000];
int B[2000001];
FILE *f;
void main(){
   int n,i,d,dk,s;
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (i=0;i<2000001;i++) B[i]=0;
	for (i=0;i<n;i++){scanf("%d",&A[i]); B[A[i]+1000000]++;}
    dk=1;d=A[0]+1000000;
	for (i=0;i<2000000;i++) if (B[i]>dk) {dk=B[i]; d=i;}
	for (i=0;i<n;i++) if (A[i]!=d-1000000) printf("%d ",A[i]);
	for (i=1;i<=dk;i++) printf("%d ",d-1000000);
}
/* решение с кеширование (TL 11)
   int n,i,j,d,dk=0,p,pk=0,s;
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	int*A=new int[n]; int*B=new int[n];
	for (i=0;i<n;i++){scanf("%d",&A[i]); B[i]=A[i];}
	for (i=0;i<n;i++){
		if (i==0 || (i!=0 && B[i]!=s)){
		if (i==0) { s=d=B[0]; } 
		else { p=B[i]; pk=0; }
		
		for (j=i;j<n;j++)
			if (i==0) {if (B[i]==B[j]) dk++;}
			else if (B[i]==B[j]) {pk++; if (B[i]!=B[j])B[j]=s;};
		if (pk>dk || (pk==dk && p<d)) {d=p; dk=pk;}
		}
	}
	for (i=0;i<n;i++) if (A[i]!=d) printf("%d ",A[i]);
	for (i=1;i<=dk;i++) printf("%d ",d);
*/