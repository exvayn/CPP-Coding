//гавнокод. работа с указателями. но! зачтено!

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

char *butf(char s[100]);
void main(){
	int f;
	char s1[100], s2[100]="", s3[100]="", *s, *z;
	gets(s1);
	z=strchr(s1,',');
	s1[1]=tolower(s1[1]);
	if (z) {
		char s4[100]=", ";
		if (*(z+2)!='{' && *(z+2)!='(' && *(z+2)!='[')
		{
			char *z1;
			z1=strchr(z+2,' ');
			f=z1-z-1;
			strcat(s4,strncpy(s2,z+2,f));
		}
		f=z-s1;

		s2[0]='\0';
		s=butf(strncpy(s2,s1,f));
		strcat(s,s4);
		strncpy(s3,s,strlen(s));

		s2[0]='\0';
		f=strlen(s1)-((z-s1)+2);
		s=butf(strncpy(s2,z+2,f));
		strcat(s3,s);
	} else {
		s=butf(s1);
		strncpy(s3,s,strlen(s));
	}
	s3[0]=toupper(s3[0]);
	printf("%s",s3);
	system("pause");
}
char *butf(char s[100]){
	int f;
	char s1[100]="",s2[100]="",s3[100]="",*i,*j;
	i=strchr(s,'{');
	j=strchr(s,'}');
	f=(j-i)-1;
	strncpy(s1,i+1,f);

	i=strchr(s,'(');
	j=strchr(s,')');
	f=(j-i)-1;
	strncpy(s2,i+1,f);

	i=strchr(s,'[');
	j=strchr(s,']');
	f=(j-i)-1;
	strncpy(s3,i+1,f);

	s[0]='\0';

	strcat(s,s1); strcat(s," "); 
	strcat(s,s2); strcat(s," "); 
	strcat(s,s3); 
	return (s);
}