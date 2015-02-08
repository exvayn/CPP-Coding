#include <iostream>

int f2(int *A, int i){
	if (i>=0){
		std::cout<<"\ndeleted.\n";
		A[i]=0;
		std::cout<<"\n\n";
		return (i-1);
	} else {std::cout<<"\nEmpty\n\n"; return (i); }
}