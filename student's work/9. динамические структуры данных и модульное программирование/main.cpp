#include <iostream>
#include <malloc.h>
int main()
{
	struct spisok{
		int val;
		struct spisok *next;
	};
	struct spisok *head,*p;
	head=(spisok*) malloc(sizeof(struct spisok));
	head->val=NULL;
	head->next=NULL;
	int k=1,n;
	char c;
	while (k){
		std::cout<<"a - add | d - delete | v - view | e - end\n Vvod: ";
		std::cin>>c;
		switch (c){
			case 'e':{k=0; break;}
			case 'a':{
				p=(spisok*) malloc(sizeof(struct spisok));
				p->next=head;
				std::cout<<"\nnew: ";
				std::cin>>n;
				std::cout<<"\n\n";
				p->val=n;
				head=p;
				break;
			}
			case 'd':{
				if (head->next==NULL) std::cout<<"\nempty"; 
				else{
					p=head->next;
					free(head);
					head=p;
					std::cout<<"\ndeleted.";
				}
				std::cout<<"\n\n";
				break;
			}
			case 'v':{
				p=head;
				std::cout<<"\nSpisok: ";
				if (p->next==NULL) std::cout<<"empty"; 
				else 
					while (p->next!=NULL){
						std::cout<<p->val<<" ";
						p=p->next;
					}
				std::cout<<"\n\n";
				break;
			}
		}
	}
	system("pause");
}