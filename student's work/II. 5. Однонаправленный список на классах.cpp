#include <iostream>

#define EMPTY is_empty()
#define PRELAST is_prelast()
#define SET_V(x) set_val(x)
#define SET_N(x) set_next(x)
#define SET(x1,x2)  set_val(x1); p->set_next(x2)
#define NEXT get_next()
#define VAL get_val()

class spisok{
	int val;
	spisok *next;
public:
	int is_prelast(void){
		return((next->next==NULL)?1:0);
	}
	int is_empty(void){
		return((next==NULL)?1:0);
	}
	int set_val(int v){
		val=v;
		return 0;
	}
	int set_next(spisok *n){
		next=n;
		return 0;
	}
	spisok* get_next(void){
		return next;
	}
	int get_val(void){
		return val;
	}
};
int main(void){
	spisok *head,*p;
	head= new spisok;
	memset(head,NULL,sizeof(spisok));
	int k=1;
	char c;
	while (k){
		std::cout<<"main: a - add | d - delete | v - view | e - end\nsearch next: s - by value | f - by num\n Vvod: ";
		std::cin>>c;
		switch (c){
			case 'e':{k=0; break;}
			case 'a':{
				int n;
				std::cout<<"\nnew: ";
				std::cin>>n;
				std::cout<<"\n\n";
				p = new spisok;
				p->SET(n,head);
				head=p;
				break;
			}
			case 'd':{
				if (head->EMPTY) std::cout<<"\nempty"; 
				else{
					p=head;
					while(!p->PRELAST) p=p->NEXT;
					free(p->NEXT->NEXT);
					p->SET(NULL,NULL);
					std::cout<<"\ndeleted.";
				}
				std::cout<<"\n\n";
				break;
			}
			case 'v':{
				p=head;
				std::cout<<"\nSpisok: ";
				if (p->EMPTY) std::cout<<"empty"; 
				else 
					while (!p->EMPTY){
						std::cout<<p->VAL<<" ";
						p=p->NEXT;
					}
				std::cout<<"\n\n";
				break;
			}
			case 's':{
				p=head;
				int x=1,n;
				std::cout<<"\nvalue: ";
				std::cin>>n;
				std::cout<<"\nNEXT ELEMENT: ";
				while (!p->EMPTY){
					if (p->VAL==n){
						if (!p->NEXT->EMPTY){
							std::cout<<p->NEXT->VAL;
							x=0;
						}
						break;
					}
					p=p->NEXT;
				}
				if (x) std::cout<<"none";
				std::cout<<"\n\n";
				break;
			}
			case 'f':{
				p=head;
				int x=1,i=1,n;
				std::cout<<"\nnumber: ";
				std::cin>>n;
				std::cout<<"\nNEXT ELEMENT: ";
				while (!p->EMPTY){
					if (i==n){
						if (!p->NEXT->EMPTY){
							std::cout<<p->NEXT->VAL;
							x=0;
						}
						break;
					}
					p=p->NEXT;
					i++;
				}
				if (x) std::cout<<"none";
				std::cout<<"\n\n";
				break;
			}
		}
	}
	return 0;
}