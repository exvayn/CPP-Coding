#include <stdio.h>
#include <math.h>
#include <iostream>
void main(){
	int n,w,i,q,h,j,a,b,c,m;
	float g;
	scanf("%d",&n);
	int*A = new int[n];
	int*B = new int[n];
	for (i=0;i<n;i++) {
	scanf("%d",&A[i]);
	}
	if (n!=1){
	h=(int)pow((float)2,(float)(n-1));
	for (i=0;i<n;i++) {
		B[i]=0;
	}
	for (i=1;i<=h-1;i++) {
        g=i; q=1;
        while (g/2==ceil(g/2)) {
           g=g/2; 
           q++;
        }
		a=b=0;
		B[q-1]=1-B[q-1];
		for (j=0;j<n;j++) {if (B[j]==0) a=a+A[j]; else b=b+A[j];}
		if (a<b) {c=a; a=b; b=c;}
		if (i==1) m=a-b; else if (m>(a-b)) m=(a-b);
	}
	} else m=A[0];
	printf("%d",m);
	system("pause");
}  