#include <stdio.h>
#include <iostream>
void main(){
	int i,n,k,d,b,x;
	scanf("%d %d",&n,&k);
	d=b=0;
	for (i=1;i<=n;i++){
		scanf("%d",&x);
		if (x>k) b=b+(x-k);
		if (x<k) d=d+(k-x);
	}
	printf("%d %d",b,d);
	system("pause");
}