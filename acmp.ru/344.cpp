#include <stdio.h>
int A[100000];
int B[100000];
void quickSortR(int *a, int n);
void main(){
   int n,i,j,x,y,x1,y1,l;
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (i=0;i<n;i++) {scanf("%d",&A[i]); B[i]=A[i];}
	quickSortR(A,n-1);
	if (A[0]>A[1]) {l=A[0]-A[1]; x=A[0]; y=A[1];}
	else {l=A[1]-A[0]; x=A[1]; y=A[0];}
	for (i=1;i<n-1;i++)
	{
		if (A[i]>A[i+1]) {x1=A[i]; y1=A[i+1];}
		else {x1=A[i+1]; y1=A[i];}

		if (x1-y1<l){
			x=x1;y=y1; l=x1-y1;
		}
	}
	for (i=0;i<n;i++) {
		if (B[i]==x) x1=i+1; 
		if (B[i]==y) y1=i+1;
	}
	printf("%d\n%d %d",l,y1,x1);
}

void quickSortR(int *a, int n) {
  int i=0,j=n,p,k; 		
  p = a[(int) n%2];		
  do {
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;
    if (i <= j) {
      k = a[i]; a[i] = a[j]; a[j] = k;
      i++; j--;
    }
  } while ( i<=j );
  if ( j > 0 ) quickSortR(a, j);
  if ( n > i ) quickSortR(a+i, n-i);
}

/* (TL 10 or 9)
#include <stdio.h>
int A[100000];
FILE *f;
void main(){
   int n,i,j,x,y,x1,y1,xi,yi,xi1,yi1;
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&A[i]);
		if (i==1) {
			if (A[0]>A[1]) {x=A[0]; y=A[1]; xi=1; yi=2;}
			else {x=A[1]; y=A[0]; xi=2; yi=1;}
		}
		if (i>1 && x-y>1)
			for (j=i-1;j>=0;j--){
				if (A[i]>A[j]) {x1=A[i]; y1=A[j]; xi1=i+1; yi1=j+1;}
				else {x1=A[j]; y1=A[i]; xi1=j+1; yi1=i+1;} 
				if (x1-y1<x-y) {x=x1; y=y1; xi=xi1; yi=yi1;}
			}
	}
	printf("%d\n%d %d",x-y,yi,xi);
}
*/