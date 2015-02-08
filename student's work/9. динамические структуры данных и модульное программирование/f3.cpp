#include <iostream>

int f3(int *A, int i){
	std::cout<<"\nSpisok: ";
	if (i>=0)
		for (int j=i;j>=0;j--)
			std::cout<<A[j]<<" ";
	else std::cout<<"empty";
	std::cout<<"\n\n";
	return (0);
}