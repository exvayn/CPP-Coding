#include <stdio.h>
#include <stdlib.h>
#include <iostream>
int ff(int x,int y);
void main(){
	int x,y,s,n,i;
	char h[3]="";
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%s",&h);
		x=((int) h[1])-48;
		switch(h[0]){
			case 'a': { y=1; break;}
			case 'b': { y=2; break;}
			case 'c': { y=3; break;}
			case 'd': { y=4; break;}
			case 'e': { y=5; break;}
			case 'f': { y=6; break;}
			case 'g': { y=7; break;}
			case 'h': { y=8; break;}
		}
		s=0;
		s+=ff(x+2,y+1);
		s+=ff(x+2,y-1);
		s+=ff(x-2,y+1);
		s+=ff(x-2,y-1);
		s+=ff(x+1,y+2);
		s+=ff(x-1,y+2);
		s+=ff(x+1,y-2);
		s+=ff(x-1,y-2);
		printf("%d\n",s);
	}
	system("pause");
}
int ff(int x,int y){
	if(x>0 && x<9 && y>0 && y<9) return 1;
	else return 0;
}