#include <stdio.h>
#include <iostream>
// ДААааааа!!! С 4 попытки!! целый день на 1 задание.
void main(){
	int n,m,k,i,tk,tk1,tt,uk,t,s,s1;
	scanf("%d %d %d",&n,&m,&k);
	int *A=new int[n];
	int *B=new int[n];
	for (i=0;i<n;i++) B[i]=0;
	for (i=0;i<n;i++) scanf("%d",&A[i]);
	tt=n;
	if (m){
		s=0;
		for (i=0;i<m;i++) 
		{   
			scanf("%d",&t);
			tk =t-s;
			if (tk<=n){
			if (B[tk-1]!=0) {s+=B[tk-1];} else {
			uk=0;s1=0; tk1=tk;
			if (tk<=n){
			while (uk<=k && tk>1){
				tk--;
				uk+=A[tk-1];
				s++;s1++;
			}
			s++;s1++;
			B[tk1-1]=s1;
			}
			}
			}
		}
			tt+=s;
	}
	printf("%d",tt);
	system("pause");
}


/* Time limit exceeded. долгий метод..

1 попытка
void main(){
	int n,m,k,i,f,tk,tt,uk;
	scanf("%d %d %d",&n,&m,&k);
	int*A=new int[n];
	for (i=0;i<n;i++) scanf("%d",&A[i]);
	if (m){
		int*B=new int[m];
		for (i=0;i<m;i++) scanf("%d",&B[i]);
		tk=1; tt=0; uk=0; f=0;
		while(tk<=n){
			tt++; 
			printf("%d %d\n",tt,tk);
				if (tt==B[f]) {
					uk=0;
					while (uk<=k && tk>1){
						tk--;
						uk+=A[tk-1];
						printf("    %d %d\n",uk,tk);
					}
					tk--;
					f++;
				}
			tk++;
		}
	} else {
	tt=n;
	}
	printf("%d",tt);
	system("pause");
}

2 попытка

#include <stdio.h>
#include <iostream>
void main(){
	int n,m,k,i,f,tk,tt,uk,t,j;
	scanf("%d %d %d",&n,&m,&k);
	int*A=new int[n];
	for (i=0;i<n;i++) scanf("%d",&A[i]);
	if (m){
		tt=0; tk=0;
		for (i=0;i<m;i++) 
		{   
			uk=0;
			scanf("%d",&t);
			while(tt<t && tk<n)
			{
				tt++; tk++;
			}
			if (tk<=n && tt==t){
			while (uk<=k && tk>1){
				tk--;
				uk+=A[tk-1];
			}
			tk--;
			}
		}
		for (j=tk;j<n;j++){
			tt++; tk++;
		}
	} else {
	tt=n;
	}
	printf("%d",tt);
	system("pause");
}

3 попытка

void main(){
	int n,m,k,i,tk,tt,uk,t,s;
	scanf("%d %d %d",&n,&m,&k);
	int*A=new int[n];
	for (i=0;i<n;i++) scanf("%d",&A[i]);
	tt=n;
	if (m){
		s=0;
		for (i=0;i<m;i++) 
		{   
			scanf("%d",&t);
			tk =t-s;
			uk=0;
			if (tk<=n){
			while (uk<=k && tk>1){
				tk--;
				uk+=A[tk-1];
				s++;
			}
			s++;
			}
			printf("%d %d\n",tt,tk);
		}
		for (i=n-s;i<n;i++) 
		{
			tt++;
			printf("%d %d\n",tt,i);
		}
	}
	printf("%d",tt);
	system("pause");
}
*/