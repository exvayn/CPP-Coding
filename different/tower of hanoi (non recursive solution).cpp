#include <stdio.h>
#include <math.h> 
#include <iostream>

void main(){
    int n;
	printf("Enter the number of discs: ");
	scanf("%d",&n);
	printf("\n \n");
    float l = 2;
    int i,i1,i2,q,s1,s2,s3,m,k,h;
    float f,j,l1,n1;
	l=n;
    l=pow(2,l);
    f=n;
    f = f/2;
    int a1 = ceil(f);  
	int *a = new int[a1];
	int *b = new int[a1];
    for (i=0; i<=a1-1;i++) {
        a[i]=0;
        b[i]=1;
    } 
    for (i=1; i<=l-1;i++) {
        j=i; q=1;
        while (j/2==ceil(j/2)) {
           j=j/2; 
           q++;
        }
        
        
        m=1; k=2; l1=2;
        if (i%4 == 0) {
            i1=2;
            while (i1<=n-1 && m==1) {
                j=i; l1=i1; l1 = pow(2,l1);  
                    if (((j/l1)==3 || (j/l1)==2 || (j/l1)==1) && (j/l1)==ceil(j/l1)) {
                        m=k;
                    } else {
                        if ((j/l1)!=ceil(j/l1)) {
                            i2=n-1;
                            if (n%2==0) k=a1+1; else k=a1;
                            while (i2>=2 && m==1) {
                                l1=i2; l1=pow(2,l1);
                                if ((j/l1)!=ceil(j/l1) || ((j/l1)>3)) {
                                    j=j-l1;
                                } else {
                                    if (i2%2 == 0) {
                                        m=k;
                                    }
                                }
                                i2=i2-1;
                                if (i2%2 == 0) k--;
                            }
                            
                        }
                        
                    }
                k++;
                i1=i1+2;
                                          
            }
        }
        switch ( b[m-1] ) { 
            case 1: {s1=1; s2=2; s3=3; break;}
            case 2: {s1=1; s2=3; s3=2; break;}
            case 3: {s1=3; s2=1; s3=2; break;}
        }
        s1+=a[m-1]; s2+=a[m-1]; s3+=a[m-1];
        if (s1>3) s1=s1-3;
        if (s2>3) s2=s2-3;
        if (s3>3) s3=s3-3;
        
        if (b[m-1]==3) {
            b[m-1]=1;
            a[m-1]=a[m-1]+1;
            if (a[m-1]>2) a[m-1]=a[m-1]-3;   
        } else b[m-1]=b[m-1]+1; 
        
      printf("Move disc %d from %d to %d\n", q, s1, s3);
     
    }
	system("pause");
}