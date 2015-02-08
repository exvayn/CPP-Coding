#include <iostream>

int f1(int *A, int i){
	std::cout<<"\nnew: ";
	std::cin>>A[i+1];
	std::cout<<"\n\n";
	return (i+1);
}